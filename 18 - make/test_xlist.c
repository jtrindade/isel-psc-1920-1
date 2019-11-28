#include "xlist.h"

#include <stdlib.h>

struct txtNode {
	struct xnode node;
	const char * text;
};

void showItems(struct xlist * list) {
	for (struct xnode * currNode = list->next; currNode != list; currNode = currNode->next) {
		struct txtNode * textNode = (struct txtNode *)currNode; 
		puts(textNode->text);
	}
}

int main(int argc, const char * argv[]) {
	
	struct xlist list;
	
	xlist_init(&list);
	
	for (int i = 0; i < argc; ++i) {
		struct txtNode * newNode =
			(struct txtNode *)malloc(sizeof (struct txtNode));
		newNode->text = argv[i];

		xlist_addLast(&list, &(newNode->node));
	}
	
	showItems(&list);
	
	while (!xlist_isEmpty(&list)) {
		struct xnode * firstNode = list.next;
		xlist_remove(firstNode);
		
		free(firstNode);
	}
	
	return 0;
}
