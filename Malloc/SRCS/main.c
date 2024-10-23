#include "ft_malloc.h"

t_heap g_heap;

int main(void) {
	init_heap();
	ft_malloc_display();
	void *ptr = ft_malloc(1024);
	extend_heap(517);
	extend_heap(1453);
	ft_malloc_display();
	char *ptr2 = (char *)ft_realloc(ptr, 4096);
	ft_malloc_display();
	extend_heap(456);
	extend_heap(235);
	ft_malloc_display();
	char *ptr3 = (char *)ft_calloc(1, 2048);
	extend_heap(648);
	extend_heap(1074);
	ft_malloc_display();
    ft_free(ptr);
	ft_free(ptr2);
    ft_free(ptr3);
	ft_malloc_display();
	return (0);
}
