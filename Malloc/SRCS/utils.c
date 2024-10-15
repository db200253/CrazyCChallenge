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

void	*extend_heap(size_t size) {
	size_t total_size = size + sizeof(t_block);
	size_t alg_size = ALIGN(total_size);
	void *new_area = mmap(NULL, alg_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (new_area == MAP_FAILED) {
		perror("mmap");
		return (0);
	}
	t_block *new_block = (t_block *)new_area;
	new_block->size = size;
	new_block->free = 1;
	new_block->next = 0;
	new_block->prev = 0;
	if (!g_heap.first)
		g_heap.first = new_block;
	else {
		t_block *last = g_heap.first;
		while (last->next)
			last = last->next;
		last->next = new_block;
	}
	g_heap.total_size += alg_size;
	g_heap.free_size += size;
	return ((void *)(new_block + 1));
}

t_block	*find_free_block(size_t size) {
	t_block *result;

	result = g_heap.first;
	while (result) {
		if (result->free && result->size >= size) {
			return (result);
		}
		result = result->next;
	}
	return (0);
}

void	ft_malloc_display() {
	if (!g_heap.first)
		return ;
	printf("\nTotal size of the heap : %zu\n", g_heap.total_size);
	printf("Free size of the heap : %zu\n", g_heap.free_size);
	printf("\nHeap structure:\n\n");
	printf("------ Start of heap ------\n");

	t_block *current = g_heap.first;
	while (current) {
		printf("| Block size: %zu | %s |\n", current->size, current->free ? "Free" : "Allocated");
		if (current->next) {
			printf("             ↓\n");
		}
	    current = current->next;
	}
	printf("------- End of heap -------\n");
}

void	init_heap() {
	g_heap.first = (t_block *)0;
	g_heap.total_size = 0;
	g_heap.free_size = 0;
}

void	merge_blocks(t_block *block) {
	t_block *tmp;
	int total_size = block->size;

	tmp = block->next;
	while (tmp && tmp->free) {
		total_size += tmp->size + sizeof(t_block);
		block->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = block;
		tmp = tmp->next;
	}
	block->size = total_size;
}

void split_block(t_block *block, size_t size) {
 	if (block->size > size + sizeof(t_block) + 4) {
        t_block *new = (t_block *)((char *)block + size + sizeof(t_block));
        new->size = block->size - size - sizeof(t_block);
        new->free = 1;
        new->prev = block;
        if (block->next) {
        	new->next = block->next;
        	block->next->prev = new;
       	} else {
          	new->next = NULL;
        }
        block->next = new;
        block->size = size;
 	}
}
