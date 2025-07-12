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
#include <stdio.h>

static void	helper_free(char **ptr, char *newvalue)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	*ptr = newvalue;
}

static char	*newline(char **save)
{
	char		*res;
	char		*newlines;
	int			i;
	int			len;

	if (!*save || !**save)
	{
		helper_free(save, NULL);
		return (NULL);
	}
	newlines = ft_strchr(*save, '\n');
	if (newlines)
	{
		len = newlines - *save + 1;
		res = calloc(len + 1, sizeof(char));
		if (!res)
			return (NULL);
		i = -1;
		while (++i < len)
			res[i] = (*save)[i];
		res[len] = '\0';
		helper_free(save, ft_strdup(newlines + 1));
		return (res);
	}
	res = ft_strdup(*save);
	helper_free(save, NULL);
	return (res);
}

static char	*readline(int fd, char *curr)
{
	char	*buffer;
	char	*new_str;
	int		bytes_read;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
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
	if (curr != NULL && curr != new_str)
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
			break;
		save = temp;
	}
	return (newline (&save));
}
