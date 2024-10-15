#include "ft_malloc.h"

void	*ft_calloc(size_t nmemb, size_t size) {
    size_t s = nmemb * size;
    void *ptr = ft_malloc(s);
    if (!ptr)
      return MALLOC_FAILED;
    memset(ptr, 0, s);
    return ptr;
}
