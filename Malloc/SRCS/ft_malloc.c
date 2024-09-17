#include "ft_malloc.h"

void	*ft_malloc(size_t size) {
	void *result;

	if (!size)
		return ((void *)0);
	t_block *free_block = find_free_block(size);
	if (!free_block)
	{
		result = extend_heap(size);
		t_block *tmp = (t_block *)((char *)result - sizeof(t_block));
		tmp->free = 0;
		return (result);
	}
	free_block->free = 0;
	result = (void *)(free_block + 1);
	return (result);
}
