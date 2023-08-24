/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:57:30 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/27 19:57:41 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		while (*(unsigned char *)s1++ == *(unsigned char *)s2++ && --n)
			;
		return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	}
	return (0);
}
