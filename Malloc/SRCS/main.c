#include "ft_malloc.h"

t_heap g_heap;

int main(void) {
	init_heap();
	ft_malloc_display();
	void *ptr = ft_malloc(1024);
	(void)ptr;
	extend_heap(517);
	extend_heap(1453);
	ft_malloc_display();
	char *ptr2 = (char *)ft_malloc(4096);
	(void)ptr2;
	extend_heap(456);
	extend_heap(235);
	ft_malloc_display();
	char *ptr3 = (char *)ft_malloc(2048);
	(void)ptr3;
	extend_heap(648);
	extend_heap(1074);
	ft_malloc_display();
	return (0);
}
