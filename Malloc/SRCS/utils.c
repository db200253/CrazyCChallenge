# include "ft_malloc.h"

int		check_limits(size_t *data_limit, size_t *as_limit) {
  struct rlimit limit;

  if (getrlimit(RLIMIT_DATA, &limit) == -1) {
    perror("getrlimit RLIMIT_DATA");
    return (0);
  }
  *data_limit = limit.rlim_cur;
  if (getrlimit(RLIMIT_AS, &limit) == -1) {
    perror("getrlimit RLIMIT_AS");
    return (0);
  }
  *as_limit = limit.rlim_cur;
  return (1);
}

void	*extend_heap(t_heap *heap, size_t size) {
  size_t total_size = size + sizeof(t_block);
  size_t alg_size = ALIGN(total_size);
  void *new_area = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  if (new_area == MAP_FAILED) {
    perror("mmap");
    return (0);
  }
  t_block *new_block = (t_block *)new_area;
  new_block->size = size;
  new_block->free = 1;
  new_block->next = 0;
  new_block->prev = 0;
  if (!heap->first)
    heap->first = new_block;
  else {
    t_block *last = heap->first;
    while (last->next)
      last = last->next;
    last->next = new_block;
  }
  heap->total_size += alg_size;
  heap->free_size += size;
  return ((void *)(new_block + 1));
}

t_block	*find_free_block(t_heap *heap, size_t size) {
  t_block *result;

  result = heap->first;
  while (result) {
    if (result->free && result->size >= size) {
      return (result);
    }
    result = result->next;
  }
  return (0);
}

void	ft_malloc_display(t_heap heap);

void	init_heap(t_heap *heap) {
  heap->first = (t_block *)0;
  heap->total_size = 0;
  heap->free_size = 0;
}

void	merge_blocks(t_block *block);

t_block	*split_block(t_block *block, size_t size);
