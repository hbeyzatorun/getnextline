/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:44:32 by htorun            #+#    #+#             */
/*   Updated: 2025/07/12 17:43:07 by htorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (helper_free(save, NULL), NULL);
	newlines = ft_strchr(*save, '\n');
	if (newlines)
	{
		len = newlines - *save + 1;
		res = ft_calloc(len + 1, sizeof(char));
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

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
	static char	*save[1024];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	if (!save[fd])
		return (NULL);
	while (!ft_strchr(save[fd], '\n'))
	{
		temp = readline(fd, save[fd]);
		if (!temp)
		{
			helper_free(&save[fd], NULL);
			return (NULL);
		}
		if (temp == save[fd])
			break ;
		save[fd] = temp;
	}
	return (newline (&save[fd]));
}
