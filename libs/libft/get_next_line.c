/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:31:59 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/11/27 02:18:38 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 128

static char	*gnl_strchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) + 1;
	while (len > 1)
	{
		if (*s++ == (unsigned char)c)
			return ((char *)s);
		len--;
	}
	return (NULL);
}

static char	*gnl_strdup(const char *s)
{
	char	*cache;
	char	*ptr;
	char	*p;

	if (!s || !*s)
		return (NULL);
	cache = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	ptr = cache;
	p = (char *)s;
	while (*s)
		*cache++ = *(char *)s++;
	*p = '\0';
	return (ptr);
}

static char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_2;
	int		s1_len;
	int		s2_len;

	if (!s1 || !*s1)
	{		
		s1 = gnl_strdup(s2);
		free((char *)s2);
		return ((char *)s1);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = ft_calloc((s1_len + s2_len) + 1, sizeof(char));
	ptr_2 = ptr + s1_len;
	if (ptr != NULL)
	{
		while (--s1_len > -1)
			ptr[s1_len] = s1[s1_len];
		while (--s2_len > -1)
			ptr_2[s2_len] = s2[s2_len];
	}
	free((char *)s1);
	free((char *)s2);
	return (ptr);
}

char	*get_next_line(int fd)
{
	ssize_t		reads;
	char		*tmp;
	static char	*cache[1024];
	char		*buffer;

	tmp = cache[fd];
	while ((fd >= 0 && BUFFER_SIZE > 0) && (!tmp || !gnl_strchr(tmp, 10)))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[reads] = '\0';
		tmp = gnl_strjoin(tmp, buffer);
	}
	buffer = gnl_strchr(tmp, 10);
	cache[fd] = gnl_strdup(buffer);
	return (tmp);
}
