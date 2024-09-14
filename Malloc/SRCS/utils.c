# include "ft_malloc.h"

int		check_limits(size_t *data_limit, size_t *as_limit) {
  struct rlimit limit;

  if (getrlimit(RLIMIT_DATA, &limit) == -1) {
    perror("getrlimit RLIMIT_DATA");
    return (-1);
  }
  *data_limit = limit.rlim_cur;
  if (getrlimit(RLIMIT_AS, &limit) == -1) {
    perror("getrlimit RLIMIT_AS");
    return (-1);
  }
  *as_limit = limit.rlim_cur;
  return (0);
}

t_block	*extend_heap(t_heap *heap, t_block *last, size_t size);

t_block	*find_free_block(t_heap *heap, size_t size);

void	ft_malloc_display(t_heap heap);

void	init_heap(t_heap *heap) {
  heap->first = (t_block *)0;
  heap->total_size = 0;
  heap->free_size = 0;
}

void	merge_blocks(t_block *block);

t_block	*split_block(t_block *block, size_t size);
