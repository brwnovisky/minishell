/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:48:33 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/07/14 20:28:01 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cache;
	char	*ptr;

	cache = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	ptr = cache;
	while (*s)
		*cache++ = *(char *)s++;
	return (ptr);
}
