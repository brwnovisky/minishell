/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:21:56 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/07/01 15:39:55 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char))
{
	char			*ptr;
	size_t			s_len;
	unsigned int	index;

	index = 0;
	s_len = ft_strlen(s);
	ptr = ft_calloc(s_len + 1, sizeof(char));
	while (index < s_len)
	{
		ptr[index] = f(index, *s++);
		index++;
	}
	return (ptr);
}
