#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_SIZE 64
#define NUM_WORDS 16384

struct wordcount {
	unsigned count;
	char word[WORD_SIZE];
};

unsigned numWords = 0;
struct wordcount words[NUM_WORDS];

/*
unsigned findWord(const char * word) {
	unsigned i;
	for (
		i = 0;
		i < numWords && strcmp(words[i].word, word);
		++i
	) ;
	return i;
}
*/

struct wordcount * findWord(const char * word) {
	unsigned i;
	struct wordcount * currWord = words;
	for (
		i = 0;
		i < numWords && strcmp(currWord->word, word);
		++i, ++currWord
	) ;
	return currWord;
}

void processWord(const char * word) {
	struct wordcount * wordCount = findWord(word);
	if (wordCount->count == 0) {
		strcpy(wordCount->word, word);
		numWords++;
	}
	wordCount->count++;
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
