#ifndef LEAK_ANALYSIS_H
# define LEAK_ANALYSIS_H

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#ifndef DOUBLE_FREE_MSG
# define _DOUBLE_FREE_MSG "You tried to free a pointer that was already freed."
#endif

#ifndef DF_MSG_L
# define DF_MSG_L 52
#endif

#ifndef BAD_FREE_MSG
# define BAD_FREE_MSG "You tried to free a pointer that wasn't allocated."
#endif

#ifndef BF_MSG_L
# define BF_MSG_L 51
#endif

# include <dlfcn.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_memalloc {
  void *ptr;
  size_t size;
  struct s_memalloc *next;
} t_memalloc;

typedef struct s_memfree {
  void *ptr;
  struct s_memfree *next;
} t_memfree;

typedef struct s_badfree {
  void *ptr;
  char *message;
  struct s_badfree *next;
} t_badfree;

typedef struct s_meminfo {
  t_memalloc *alloc;
  t_memfree *free;
  t_badfree *bad;
} t_meminfo;

extern t_meminfo *g_leak_analysis;
static pthread_mutex_t g_leak_analysis_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Manipulation des linked lists pour garder les opérations sur la mémoire */
void  add_memalloc(void *ptr, size_t size);
void  add_memfree(void *ptr);
void  add_bad_free(void *ptr, int flag);
t_memalloc *find_memalloc(void *ptr);
void  remove_alloc(void *ptr);
void  init_leak_analysis();

/* Wrappers pour les fonctions de mémoire */
void  *my_malloc(size_t size);
void  *my_calloc(size_t nmemb, size_t size);
void  *my_realloc(void *ptr, size_t size);
void   my_free(void *ptr);

/* Affichage des leaks */
void  print_memalloc();

#endif
