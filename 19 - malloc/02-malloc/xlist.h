
#define OFFSET_OF(TYPE, FIELD) \
	((unsigned int)(unsigned long)&(((TYPE *)0)->FIELD))

#define CONTAINER_OF(PTR, TYPE, FIELD) \
	((TYPE *)(((char *)PTR) - OFFSET_OF(TYPE, FIELD)))

#define xlist xnode

struct xnode {
	struct xnode * next;
	struct xnode * prev;
};

void xlist_init(struct xlist * list);

int xlist_isEmpty(struct xlist * list);

void xlist_insertAfter(struct xnode * refNode, struct xnode * newNode);

void xlist_insertBefore(struct xnode * refNode, struct xnode * newNode);

void xlist_remove(struct xnode * node);

#define xlist_addFirst xlist_insertAfter

#define xlist_addLast xlist_insertBefore
