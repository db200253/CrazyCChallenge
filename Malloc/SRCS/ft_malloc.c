#include "ft_malloc.h"

void	*ft_malloc(size_t size) {
	void *result;

	if (!size)
		return MALLOC_FAILED;
	t_block *free_block = find_free_block(size);
	if (!free_block)
	{
		result = extend_heap(size);
        if (!result)
          return MALLOC_FAILED;
		t_block *tmp = (t_block *)((char *)result - sizeof(t_block));
		tmp->free = 0;
		return (result);
	}
    if (free_block->size > size + sizeof(t_block)) {
     	split_block(free_block, size);
    }
	free_block->free = 0;
	result = (void *)(free_block + 1);
	return (result);
}
