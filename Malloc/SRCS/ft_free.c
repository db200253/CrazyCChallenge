#include "ft_malloc.h"

void	ft_free(void *ptr) {
  	if (!ptr)
          return;
    t_block	*block = (t_block *)ptr - sizeof(t_block);
    block->free = 1;
    merge_blocks(block);
}
