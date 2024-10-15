#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

# define ALIGNMENT 8
# define ALIGN(size) (((size) + ALIGNMENT - 1) & ~(ALIGNMENT - 1))
# define PAGE_SIZE sysconf(_SC_PAGE_SIZE)
# define MIN_BLOCK_SIZE sizeof(t_block)

//Macros pour échec du malloc
# define MALLOC_FAILED ((void *)0)
# define MALLOC_MSG_ERROR "Malloc alloction failed"

//Structure pour représenter les blocs de mémoire alloués
typedef struct s_block {
  size_t			size;
  int	            free;
  struct s_block	*next;
  struct s_block	*prev;
} t_block;

//Structure pour représenter la heap
typedef struct s_heap {
  t_block		*first;
  size_t		total_size;
  size_t		free_size;
} t_heap;

extern t_heap	g_heap;

//Fonctions utilitaires
int		check_limits(size_t *data_limit, size_t *as_limit);
void	*extend_heap(size_t size);
t_block	*find_free_block(size_t size);
void	ft_malloc_display();
void	init_heap();
void	merge_blocks(t_block *block);
void split_block(t_block *block, size_t size);

//Fonctions à redéfinir
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t size);

#endif
