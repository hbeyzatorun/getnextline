/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:59:25 by htorun            #+#    #+#             */
/*   Updated: 2025/07/10 22:59:29 by htorun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *s, int c);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *s);

#endif
