#include "xmalloc.h"
#include "xlist.h"

char space[4*1024*1024];

struct mblock {
	unsigned int length;
	struct xnode node;
};

struct xlist free_blocks;

void xmalloc_init() {
	xlist_init(&free_blocks);
	
	struct mblock * pFirstBlock = (struct mblock *)space;
	pFirstBlock->length = sizeof (space) - sizeof (pFirstBlock->length);
	
	xlist_addLast(&free_blocks, &(pFirstBlock->node));
}

void * xmalloc(unsigned int nbytes) {
	struct xnode * currNode;
	for (currNode = free_blocks.next; currNode != &free_blocks; currNode = currNode->next) {
		struct mblock * pblock = CONTAINER_OF(currNode, struct mblock, node);
		if (pblock->length >= nbytes) {
			xlist_remove(currNode);
			return currNode;
		}
	}
	return 0;
}

void xfree(void * pmem) {
	xlist_addFirst(&free_blocks, (struct xnode *)pmem);
}
