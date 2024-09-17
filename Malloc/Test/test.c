#include "ft_malloc.h"

# define BLUE_TEXT "\033[94m"
# define RESET_TEXT "\033[95m"

void print_blue_frame(const char *text) {
  int width = 50;
  int padding = (width - (2 + strlen(text))) / 2;
  printf(BLUE_TEXT);
  for (int i = 0; i < width; i++) {
    printf("=");
  }
  printf("\n");
  printf(BLUE_TEXT);
  printf("=");
  for (int i = 0; i < padding; i++) {
    printf(" ");
  }
  printf("%s", text);
  for (int i = 0; i < (int)(width - (padding + 2 + strlen(text))); i++) {
    printf(" ");
  }
  printf("=\n");
  printf(BLUE_TEXT);
  for (int i = 0; i < width; i++) {
    printf("=");
  }
  printf("\n" RESET_TEXT);
}

void    __test_init_heap(void) {
  t_heap	heap;
  init_heap(&heap);
  print_blue_frame("Heap initialization");
  printf("-----------------------------------\n\n");
  printf("Heap initialized\n\n");
  printf("First bloc of the heap : %p\n", (void *)heap.first);
  printf("Total size of the heap : %lu\n", heap.total_size);
  printf("Free size of the heap : %lu\n", heap.free_size);
  printf("-----------------------------------\n\n");
}

void  __test_check_limits(void) {
  size_t data_limit, as_limit;
  print_blue_frame("Limit check");
  printf("------------------------------------\n\n");
  if (!check_limits(&data_limit, &as_limit)) {
    printf("Reached heap limits\n");
  } else {
    printf("Heap limits not reached\n");
    printf("Data limit of the heap is %lu\n", data_limit);
    printf("AS limit of the heap is %lu\n", as_limit);
  }
  printf("-------------------------------------\n\n");
}

void  __test_extend_heap(void) {
  t_heap	heap;
  init_heap(&heap);
  print_blue_frame("Heap extension");
  printf("------------------------------------\n\n");
  void *ptr = extend_heap(&heap, 1024);
  if (ptr) {
    printf("Heap extended successfully. Pointer: %p\n", ptr);
    printf("Total heap size: %zu bytes\n", heap.total_size);
    printf("Free size in heap: %zu bytes\n", heap.free_size);
  } else {
    printf("Failed to extend heap.\n");
  }
  void *ptr2 = extend_heap(&heap, 4096);
  if (ptr2) {
    printf("Heap extended successfully. Pointer: %p\n", ptr2);
    printf("Total heap size: %zu bytes\n", heap.total_size);
    printf("Free size in heap: %zu bytes\n", heap.free_size);
  } else {
    printf("Failed to extend heap.\n");
  }
  void *ptr3 = extend_heap(&heap, 2756);
  if (ptr3) {
    printf("Heap extended successfully. Pointer: %p\n", ptr3);
    printf("Total heap size: %zu bytes\n", heap.total_size);
    printf("Free size in heap: %zu bytes\n", heap.free_size);
  } else {
    printf("Failed to extend heap.\n");
  }
  printf("-------------------------------------\n\n");
}

void __test_find_free_block(void) {
  t_heap	heap;
  init_heap(&heap);
  print_blue_frame("Finding free block");
  printf("-------------------------------------\n\n");
  void *ptr = extend_heap(&heap, 1024);
  if (ptr)
    printf("Heap extended successfully.\n");
  void *ptr2 = extend_heap(&heap, 4096);
  if (ptr2)
    printf("Heap extended successfully.\n");
  void *ptr3 = extend_heap(&heap, 2756);
  if (ptr3)
    printf("Heap extended successfully.\n");
  t_block *block, *block2, *block3;
  block = find_free_block(&heap, 1024);
  if (block) {
    printf("Found a free block with size %zu bytes\n", block->size);
  } else {
    printf("No suitable free block found\n");
  }
  block2 = find_free_block(&heap, 4096);
  if (block2) {
    printf("Found a free block with size %zu bytes\n", block2->size);
  } else {
    printf("No suitable free block found\n");
  }
  block3 = find_free_block(&heap, 16742);
  if (block3) {
    printf("Found a free block with size %zu bytes\n", block3->size);
  } else {
    printf("No suitable free block found\n");
  }
  printf("-------------------------------------\n\n");
}

void __test_merge_blocks(void) {
	t_heap heap;
	init_heap(&heap);
	print_blue_frame("Merging blocks");
	printf("-------------------------------------\n\n");
	void *ptr = extend_heap(&heap, 1024);
	if (ptr)
	  printf("Heap extended successfully.\n");
	void *ptr2 = extend_heap(&heap, 4096);
	if (ptr2)
	  printf("Heap extended successfully.\n");
	void *ptr3 = extend_heap(&heap, 2756);
	if (ptr3)
	  printf("Heap extended successfully.\n");
	t_block *block = heap.first;
	merge_blocks(block);
	t_block *test = find_free_block(&heap, 7800);
	if (test){
	  printf("Found a free block with size %zu bytes\n", test->size);
	} else {
	  printf("No suitable free block found. Error in merging.\n");
	}
	printf("-------------------------------------\n\n");
}

void __test_malloc_display(void) {
	t_heap heap;
	init_heap(&heap);
	print_blue_frame("Displaying blocks");
	printf("-------------------------------------\n\n");
	for (int i = 0;i < 10; ++i) {
		void *ptr = extend_heap(&heap, rand()%4096 + 2048);
		(void)ptr;
	}
	ft_malloc_display(&heap);
	printf("-------------------------------------\n\n");
}

int main(void) {
  __test_init_heap();
  __test_check_limits();
  __test_extend_heap();
  __test_find_free_block();
  __test_merge_blocks();
  srand(time(NULL));
  __test_malloc_display();
  return (0);
}
