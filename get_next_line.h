#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_strdup(const char *s);

size_t	*ft_strrchr(char *s, int c);
size_t	ft_strlen(const char *s);

#endif