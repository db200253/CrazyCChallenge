# include "ft_malloc.h"

int		check_limits(size_t *data_limit, size_t *hard_limit);
t_block	*extend_heap(t_heap *heap, t_block *last, size_t size);
t_block	*find_free_block(t_heap *heap, size_t size);
void	ft_malloc_display(t_heap heap);
void	init_heap(t_heap *heap);
void	merge_blocks(t_block *block);
t_block	*split_block(t_block *block, size_t size);