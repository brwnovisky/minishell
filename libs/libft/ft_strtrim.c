/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:53:48 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/30 18:17:07 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*trim;
	char	*rev;

	trim = (char *)set;
	rev = (char *)s1 + ft_strlen(s1) - 1;
	while (*set && *s1)
	{
		if (*s1 == *set || *rev == *set)
		{
			s1 += *s1 == *set;
			rev -= *rev == *set;
			set = trim;
		}
		else
			set++;
	}
	trim = ft_calloc(((rev - s1) + 2) * (*s1 > 0) + (*s1 == 0), sizeof(char));
	ft_strlcpy(trim, s1, ((rev - s1) + 2) * (*s1 > 0) + (*s1 == 0));
	return (trim);
}
