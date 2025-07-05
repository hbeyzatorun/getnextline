#include "get_next_line.h"
#include <stdlib.h>

static char	*newline(char *save)
{
	char	*line;
	char	*newline;
	int		len;
	char	*res;
	int		i;
    char *temp;
	if (!save)
		return (NULL);
	newline = ft_strrchr(save, '\n'); 
	if (newline)
	{
		len = newline - save + 1;
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		while ( i < len)
		{
            res[i] = save[i];
			i++;
		}
        res[i] = '\0';
        temp = ft_strdup(newline + 1);
        free(*save);
	}
}
static char *tmp(char *start)
{
    char *temp;
    char *newline;
    temp = ft_strdup(newline + 1);
    free(*start);
    *start = temp;
}
char	*get_next_line(int fd)
{
	static char *s;
	s = calloc(2, sizeof(char));
	if (!s)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}