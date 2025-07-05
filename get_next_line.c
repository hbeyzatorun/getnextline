#include "get_next_line.h"
#include <stdlib.h>

static char	*newline(char **save)
{
	char	*line;
	char	*newline;
	int		len;
	char	*res;
	int		i;
	char	*temp;

	if (!save)
		return (NULL);
	newline = ft_strchr(*save, '\n');
	if (newline)
	{
		len = newline - *save + 1;
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		while (i < len)
		{
			res[i] = *save[i];
			i++;
		}
		res[i] = '\0';
		temp = ft_strdup(newline + 1);
		free(*save);
		*save = temp;
		return (res);
	}
}

char	readline(int fd, char **save)
{
	char	*buffer;
	int		read_byte;

	read_byte = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_byte)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte <= 0)
			return (NULL);
	}
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