/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:49:17 by root              #+#    #+#             */
/*   Updated: 2023/08/20 17:42:33 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*strchr_mod(const char *str, int c)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == (char) c)
			{
				str++;
				return ((char *)str);
			}
			str++;
		}
		if ((char) c == '\0' && *str == '\0')
			return ((char *)str);
	}
	return (NULL);
}

int	strcmp_mod(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (1);
	while (i < len)
	{
		if (s1[i] != s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (SUCCES);
}

int	ft_atoi64(const char *nptr)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{	
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + *nptr++ - '0';
	if ((sign == -1 && result > (((size_t)INT64_MAX)) + 1) \
	|| (sign == 1 && result > (size_t)INT64_MAX))
		return (2);
	else
		return (result * sign);
}
