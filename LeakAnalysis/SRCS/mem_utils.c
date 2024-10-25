#include "leak_analysis.h"

void add_memalloc(void *ptr, size_t size) {
  t_memalloc *alloc = g_leak_analysis->alloc;
  while (alloc->next) {
    alloc = alloc->next;
  }
  t_memalloc *new = (t_memalloc *)malloc(sizeof(t_memalloc));
  if (!new) return;
  new->ptr = ptr;
  new->size = size;
  new->next = NULL;
  alloc->next = new;
}

void add_memfree(void *ptr) {
  t_memfree *free = g_leak_analysis->free;
  while (free->next) {
    free = free->next;
  }
  t_memfree *new = (t_memfree *)malloc(sizeof(t_memfree));
  if (!new) return;
  new->ptr = ptr;
  new->next = NULL;
  free->next = new;
}

void add_bad_free(void *ptr, int flag) {
  t_badfree *free = g_leak_analysis->bad;
  while (free->next) {
    free = free->next;
  }
  t_badfree *new = (t_badfree *)malloc(sizeof(t_badfree));
  if (!new) return;
  new->ptr = ptr;
  if (!flag) {
    new->message = BAD_FREE_MSG;
  } else {
    new->message = DOUBLE_FREE_MSG;
  }
  new->next = NULL;
  free->next = new;
}

t_memalloc *find_memalloc(void *ptr) {
  t_memalloc *alloc = NULL;
  t_memalloc *head = g_leak_analysis->alloc;
  while (head->next) {
    if (head->ptr == ptr) {
      alloc = head;
      return alloc;
    }
    head = head->next;
  }
  return NULL;
}

int find_memfree(void *ptr) {
  t_memfree *free = g_leak_analysis->free;
  while (free->next) {
    if (free->ptr == ptr) {
      return 1;
    }
    free = free->next;
  }
  return 0;
}

void remove_alloc(void *ptr) {
  t_memalloc *alloc = find_memalloc(ptr);
  t_memalloc *prev = g_leak_analysis->alloc;
  if (!alloc) {
    if (find_memfree(ptr)) {
      add_bad_free(ptr, 1);
    } else {
      add_bad_free(ptr, 0);
    }
  }
  while (prev->next != alloc) {
    prev = prev->next;
  }
  prev->next = alloc->next;
  free(alloc);
}

void init_leak_analysis() {
  g_leak_analysis->alloc = NULL;
  g_leak_analysis->free = NULL;
  g_leak_analysis->bad = NULL;
}

void clear_leak_analysis() {
  t_memalloc *alloc = g_leak_analysis->alloc;
  t_memalloc *tmp;
  while (alloc->next) {
    tmp = alloc->next;
    free(alloc);
    alloc = tmp;
  }
  t_memfree *mem_free = g_leak_analysis->free;
  t_memfree *tmp2;
  while (mem_free->next) {
    tmp2 = mem_free->next;
    free(mem_free);
    mem_free = tmp2;
  }
  t_badfree *bad_free = g_leak_analysis->bad;
  t_badfree *tmp3;
  while (bad_free->next) {
    tmp3 = bad_free->next;
    free(bad_free);
    bad_free = tmp3;
  }
}