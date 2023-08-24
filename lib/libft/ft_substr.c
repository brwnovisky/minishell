/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:50:59 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/07/05 20:55:56 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	index;

	if (!len)
		return (NULL);
	index = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	while (len-- && s[start])
		ptr[index++] = s[start++];
	ptr[index] = 0;
	return (ptr);
}
