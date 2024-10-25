#ifndef LEAK_ANALYSIS_H
# define LEAK_ANALYSIS_H

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#ifndef DOUBLE_FREE_MSG
# define DOUBLE_FREE_MSG "You tried to free a pointer that was already freed."
#endif

#ifndef BAD_FREE_MSG
# define BAD_FREE_MSG "You tried to free a pointer that wasn't allocated."
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

// Manipulation des listes chaînées pour la gestion de la mémoire
void add_memalloc(void *ptr, size_t size);
void add_memfree(void *ptr);
void add_bad_free(void *ptr, int flag);
t_memalloc *find_memalloc(void *ptr);
int find_memfree(void *ptr);
void remove_alloc(void *ptr);
void init_leak_analysis();
void clear_leak_analysis();

// Wrappers pour les fonctions d'allocation de mémoire
void *my_malloc(size_t size);
void *my_calloc(size_t nmemb, size_t size);
void *my_realloc(void *ptr, size_t size);
void my_free(void *ptr);

// Affichage des fuites mémoire en fin d'exécution
void print_memalloc();

#endif
