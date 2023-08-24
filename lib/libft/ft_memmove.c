/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:04:05 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/23 16:56:37 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (src < dest && dest <= src + (n - 1))
	{
		dest += n - 1;
		src += n - 1;
		while (n--)
			*(unsigned char *)dest-- = *(unsigned char *)src--;
	}
	else
		return (ft_memcpy(dest, src, n));
	return (ptr);
}
