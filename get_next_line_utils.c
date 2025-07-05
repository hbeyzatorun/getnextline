#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	while (s[i])
		i++;
	return (i);
}

size_t	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			;
		return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char	*ft_strjoin(const char *s1, char const *s2)
{
	int i;
	int j;
	int len1;
	int len2;
	char *res;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		res[i + j] = s2[i + j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}