#include "xlist.h"

void xlist_init(struct xnode * list) {
	list->next = list->prev = list;
}

int xlist_isEmpty(struct xnode * list) {
	return list == list->next;
}

void xlist_insertAfter(struct xnode * refNode, struct xnode * newNode) {
	newNode->next = refNode->next;
	newNode->prev = refNode;
	
	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
}

void xlist_insertBefore(struct xnode * refNode, struct xnode * newNode) {
	newNode->next = refNode;
	newNode->prev = refNode->prev;
	
	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
}

void xlist_remove(struct xnode * node) {
	node->next->prev = node->prev;
	node->prev->next = node->next;
}
