#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t size) {
    if (!ptr)
        return ft_malloc(size);
    if (!size) {
        ft_free(ptr);
        return MALLOC_FAILED;
    }
    t_block *block = (t_block *)ptr - sizeof(t_block);
    if (block->size >= size) {
        if (block->size > size + sizeof(t_block))
            split_block(block, size);
        return ptr;
    }
    void *new_ptr = ft_malloc(size);
    if (!new_ptr)
      return MALLOC_FAILED;
    memcpy(new_ptr, ptr, size);
    ft_free(ptr);
    return new_ptr;
}
