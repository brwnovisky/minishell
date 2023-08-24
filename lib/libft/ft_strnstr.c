/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:23:39 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/23 02:03:32 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	char	*ptr;
	char	*ptr_l;

	if (!*little)
		return ((char *)big);
	ptr_l = (char *)little;
	while (big && *big && len--)
	{
		if (*big == *little)
		{
			ptr = (char *)big;
			while (!*little || (*ptr == *little
					&& len + 1 > (size_t)(ptr - big)))
			{
				if (!*little)
					return ((char *)big);
				little++;
				ptr++;
			}
		}
		big++;
		little = ptr_l;
	}
	return (NULL);
}
