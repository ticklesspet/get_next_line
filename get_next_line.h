#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// includes
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

// functions
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c);

char	*ft_strjoin(char *left_str, char *buf);

char	*ft_strdup(const char *str);

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif