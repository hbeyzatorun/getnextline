/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:44:32 by htorun            #+#    #+#             */
/*   Updated: 2025/07/10 22:58:43 by htorun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static void	helper_free(char **ptr, char *newvalue)
{
	if (*ptr)
		free(*ptr);
	*ptr = newvalue;
}

static char	*newline(char **save)
{
	char		*res;
	char		*newlines;
	int			i;
	int			len;

	if (!*save || !**save)
		return (NULL);
	newlines = ft_strchr(*save, '\n');
	if (newlines)
	{
		len = newlines - *save + 1;
		res = malloc(len + 1);
		if (!res)
			return (NULL);
		i = -1;
		while (++i < len)
			res[i] = (*save)[i];
		res[len] = '\0';
		return (helper_free(save, ft_strdup(newlines + 1)), res);
	}
	res = ft_strdup(*save);
	return (helper_free(save, NULL), res);
}

static char	*readline(int fd, char *curr)
{
	char	*buffer;
	char	*new_str;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (curr);
	}
	buffer[bytes_read] = '\0';
	new_str = ft_strjoin(curr, buffer);
	free (buffer);
	if (!new_str)
		return (NULL);
	free (curr);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		temp = readline(fd, save);
		if (!temp)
		{
			helper_free(&save, NULL);
			return (NULL);
		}
		if (temp == save)
			return (newline(&save));
		save = temp;
	}
	return (newline (&save));
}
