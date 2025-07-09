#include "get_next_line.h"
#include <stdlib.h>

static char *newline(char **save)
{
    char *res;
    char *newlines;
    int i;
    int len;

    if (!*save || !**save)
        return (NULL);

    newlines = ft_strchr(*save, '\n');
    if (newlines)
    {
        len = newlines - *save + 1;
        res = malloc(len + 1);
        if (!res)
            return (NULL);
        ft_memmove(res, *save, len);
        res[len] = '\0';

        char *temp = ft_strdup(newlines + 1);
        free(*save);
        *save = temp;
    }
    else
    {
        res = ft_strdup(*save);
        free(*save);
        *save = NULL;
    }
    return (res);
}

static char *readline(int fd, char *save)
{
    char *buffer;
    char *temp;
    ssize_t bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (!ft_strchr(save, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(save, buffer);
        if (!temp)
        {
            free(buffer);
            return (NULL);
        }
        free (save);
        save = temp;
    }
    free(buffer);
    return (save);
}

char *get_next_line(int fd)
{
    static char *save;
    char    *line;
    char    *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	temp = readline(fd, save);
    if (!temp)
    {
        free(save);
        save = NULL;
        return (NULL);
    }
    save = temp;
    line = newline(&save);
    return (line);
}
