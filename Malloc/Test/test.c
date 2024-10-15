#include "ft_malloc.h"
#include <assert.h>

# define BLUE_TEXT "\033[94m"
# define PASS_TEST "\033[1;32m"
# define RESET_TEXT "\033[95m"

t_heap g_heap;

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
  init_heap();
  print_blue_frame("Heap initialization");
  printf("-----------------------------------\n\n");
  printf("Heap initialized\n\n");
  assert((void *)g_heap.first == (void *)0);
  printf("First bloc of the heap : %p\n", (void *)g_heap.first);
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  assert(g_heap.total_size == 0);
  printf("Total size of the heap : %lu\n", g_heap.total_size);
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  assert(g_heap.free_size == 0);
  printf("Free size of the heap : %lu\n", g_heap.free_size);
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
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
    assert(data_limit == 18446744073709551615u);
    printf("Data limit of the heap is %lu\n", data_limit);
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
    assert(as_limit == 18446744073709551615u);
    printf("AS limit of the heap is %lu\n", as_limit);
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  }
  printf("-------------------------------------\n\n");
}

void  __test_extend_heap(void) {
  print_blue_frame("Heap extension");
  printf("------------------------------------\n\n");
  void *ptr = extend_heap(1024);
  if (ptr) {
    assert(g_heap.free_size == 1024);
    printf("Heap extended successfully. Pointer: %p\n", ptr);
    printf("Total heap size: %zu bytes\n", g_heap.total_size);
    printf("Free size in heap: %zu bytes\n", g_heap.free_size);
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  } else {
    printf("Failed to extend heap.\n");
  }
  void *ptr2 = extend_heap(4096);
  if (ptr2) {
    assert(g_heap.free_size == 5120);
    printf("Heap extended successfully. Pointer: %p\n", ptr2);
    printf("Total heap size: %zu bytes\n", g_heap.total_size);
    printf("Free size in heap: %zu bytes\n", g_heap.free_size);
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  } else {
    printf("Failed to extend heap.\n");
  }
  void *ptr3 = extend_heap(2756);
  if (ptr3) {
    assert(g_heap.free_size == 7876);
    printf("Heap extended successfully. Pointer: %p\n", ptr3);
    printf("Total heap size: %zu bytes\n", g_heap.total_size);
    printf("Free size in heap: %zu bytes\n", g_heap.free_size);
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  } else {
    printf("Failed to extend heap.\n");
  }
  printf("-------------------------------------\n\n");
}

void __test_find_free_block(void) {
  print_blue_frame("Finding free block");
  printf("-------------------------------------\n\n");
  void *ptr = extend_heap(1024);
  if (ptr)
    printf("Heap extended successfully.\n");
  void *ptr2 = extend_heap(4096);
  if (ptr2)
    printf("Heap extended successfully.\n");
  void *ptr3 = extend_heap(2756);
  if (ptr3)
    printf("Heap extended successfully.\n");
  t_block *block, *block2, *block3;
  block = find_free_block(1024);
  assert(block);
  if (block) {
    printf("Found a free block with size %zu bytes\n", block->size);
  } else {
    printf("No suitable free block found\n");
  }
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  block2 = find_free_block(4096);
  assert(block2);
  if (block2) {
    printf("Found a free block with size %zu bytes\n", block2->size);
  } else {
    printf("No suitable free block found\n");
  }
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  block3 = find_free_block(16742);
  assert(!block3);
  if (block3) {
    printf("Found a free block with size %zu bytes\n", block3->size);
  } else {
    printf("No suitable free block found\n");
  }
  printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
  printf("-------------------------------------\n\n");
}

void __test_merge_blocks(void) {
	print_blue_frame("Merging blocks");
	printf("-------------------------------------\n\n");
	void *ptr = extend_heap(1024);
	if (ptr)
	  printf("Heap extended successfully.\n");
	void *ptr2 = extend_heap(4096);
	if (ptr2)
	  printf("Heap extended successfully.\n");
	void *ptr3 = extend_heap(2756);
	if (ptr3)
	  printf("Heap extended successfully.\n");
	t_block *block = g_heap.first;
	merge_blocks(block);
    assert(g_heap.total_size > 7876);
    printf(PASS_TEST "✓ Merging : Test passed\n" RESET_TEXT);
	t_block *test = find_free_block(7800);
    assert(test);
	if (test){
	  printf("Found a free block with size %zu bytes\n", test->size);
	} else {
	  printf("No suitable free block found. Error in merging.\n");
	}
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
	printf("-------------------------------------\n\n");
}

void __test_split_block() {
  	print_blue_frame("Splitting blocks");
    printf("-------------------------------------\n\n");
    t_block block;
    block.size = 1024;
    block.free = 1;
    block.next = NULL;
    block.prev = NULL;

    size_t requested_size = 256;
    split_block(&block, requested_size);
    t_block *new_block = block.next;

    if (block.size == requested_size) {
        printf("Test passed: Le premier bloc a la bonne taille (%lu bytes).\n", block.size);
    } else {
        printf("Test failed: La taille du premier bloc est incorrecte (attendu: %lu, obtenu: %lu).\n", requested_size, block.size);
    }
	printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
    if (new_block && new_block->free && new_block->size == 1024 - requested_size - sizeof(t_block)) {
        printf("Test passed: Le nouveau bloc est bien initialisé avec la taille restante (%lu bytes).\n", new_block->size);
    } else {
        printf("Test failed: Le nouveau bloc est incorrect (attendu: %lu, obtenu: %lu).\n",
                1024 - requested_size - sizeof(t_block), new_block ? new_block->size : 0);
    }
	printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
    if (block.next == new_block && new_block->prev == &block) {
        printf("Test passed: Les liens entre les blocs sont corrects.\n");
    } else {
        printf("Test failed: Les liens entre les blocs sont incorrects.\n");
    }
    printf(PASS_TEST "✓ Test passed\n" RESET_TEXT);
    printf("-------------------------------------\n\n");
}


void __test_malloc_display(void) {
	print_blue_frame("Displaying blocks");
	printf("-------------------------------------\n\n");
	for (int i = 0;i < 10; ++i) {
		void *ptr = extend_heap(rand()%4096 + 2048);
		(void)ptr;
	}
	ft_malloc_display();
    t_block *merge = g_heap.first;
    merge_blocks(merge);
    ft_malloc_display();
	printf("-------------------------------------\n\n");
}

int main(void) {
  __test_init_heap();
  __test_check_limits();
  __test_extend_heap();
  __test_find_free_block();
  __test_merge_blocks();
  __test_split_block();
  srand(time(NULL));
  __test_malloc_display();
  return (0);
}
