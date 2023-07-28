/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:48:20 by bluiz-al          #+#    #+#             */
/*   Updated: 2023/01/11 21:17:26 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_2;
	int		s1_len;
	int		s2_len;

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
	return (ptr);
}
