#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_SIZE 64
#define NUM_WORDS 32768

struct listNode {
	struct listNode * next;
};

struct wordcount {
	struct listNode node;
	unsigned count;
	char word[WORD_SIZE];
};

unsigned numWords = 0;
struct wordcount words[NUM_WORDS];

struct wordcount * newWordCount() {
	return &words[numWords++];
}

struct listNode * list = NULL;

struct listNode * findNode(const char * word) {
	struct listNode * curr;
	for (
		curr = list;
		curr && strcmp(((struct wordcount *)curr)->word, word);
		curr = curr->next
	);
	return curr;
}

void insertNode(struct listNode * node) {
	node->next = list;
	list = node;
}

void processWord(const char * word) {
	//printf("PROCESSING: %s\n", word);
	struct wordcount * wordcnt = (struct wordcount *)findNode(word);
	if (!wordcnt) {
		wordcnt = newWordCount();
		strcpy(wordcnt->word, word);
		wordcnt->count = 0;
		insertNode(&(wordcnt->node));
	} 
	wordcnt->count++;
}

void showResults() {
	for (unsigned i = 0; i < numWords; ++i) {
		printf("%s : %u\n", words[i].word, words[i].count);
	}
}

bool isWordChar(int c) {
	return strchr(" \t\r\n.,:;!?()\"'-", c) == NULL;
}

enum InWordState { IN_SPACE, IN_WORD };

void processFile(FILE * f) {
	int c, idx = 0, state = IN_SPACE;
	char word[WORD_SIZE];
	while ((c = fgetc(f)) != EOF) {
		c = tolower(c);
		if (isWordChar(c)) {		
			word[idx++] = c;
			state = IN_WORD;
		} else {
			if (state == IN_WORD) {
				word[idx] = '\0';
				processWord(word);
				idx = 0;
				state = IN_SPACE;
			}
		}
	}
	if (state == IN_WORD) {
		word[idx] = '\0';
		processWord(word);
	}
	showResults();
}

int main(int argc, char *argv[]) {
	
	if (argc > 2) {
		fprintf(stderr, "use: %s [file]\n", argv[0]);
		return 1;
	}

	if (argc == 2) {
		FILE * f = fopen(argv[1], "r");
		if (!f) {
			fprintf(
				stderr,
				"error opening \"%s\": %s\n",
				argv[1],
				strerror(errno)
			);
			return 2;
		}
		
		processFile(f);
		
		fclose(f);
	} else {
		processFile(stdin);
	}
	
	return 0;
}
