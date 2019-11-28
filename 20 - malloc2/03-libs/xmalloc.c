#include "xmalloc.h"
#include "xlist.h"

#define REF_N (sizeof(unsigned long) - 1)

#define REF_MULT(N) ((N + REF_N) & ~REF_N)

#define NORMALIZE_NBYTES(N) \
	((N < sizeof (struct xnode)) ? sizeof (struct xnode) : REF_MULT(N))

char space[4*1024*1024];

struct mblock {
	unsigned long length;
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
	// Alocar pelo menos 16 bytes e sempre um múltiplo de 8.
	nbytes = NORMALIZE_NBYTES(nbytes);
	
	// Percorrer todos os blocos livres...
	struct xnode * currNode;
	for (currNode = free_blocks.next; currNode != &free_blocks; currNode = currNode->next) {
		struct mblock * pblock = CONTAINER_OF(currNode, struct mblock, node);
		// ... até encontrar um com tamanho suficiente.
		if (pblock->length >= nbytes) {
			unsigned int newBlockSize = nbytes + OFFSET_OF(struct mblock, node);
			// Verificar se é possível partir o bloco encontrado em 2
			if (pblock->length - newBlockSize < sizeof (struct xnode)) {
				// Bloco não pode ser partido em 2. Devolvido inteiro.
				xlist_remove(currNode);
				return currNode;
			} else {
				// Guardar início do novo bloco em pNewBlock.
				struct mblock * pNewBlock = (struct mblock *)
					(((char *)currNode) + pblock->length - newBlockSize);
				
				// Registar tamanho do novo bloco.
				pNewBlock->length = nbytes;
				
				// Corrigir tamanho do bloco deixado na lista.
				pblock->length -= newBlockSize;

				// Retornar novo bloco.
				return &(pNewBlock->node);
			}
		}
	}
	return 0;
}

void xfree(void * pmem) {
	xlist_addFirst(&free_blocks, (struct xnode *)pmem);
}
