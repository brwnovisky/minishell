/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:42:27 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/08/13 00:43:11 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*printf_hex(unsigned long int n, char c, char *p, int *i)
{
	char				*h;
	unsigned long int	divisor;

	divisor = 1;
	*i = 1;
	if (c == 'x' || c == 'X')
		n = (n > 0) * ((unsigned int) n);
	while (n != 48 && n / divisor > 15)
	{
		divisor *= 16;
		*i += 1;
	}
	p = malloc(*i * sizeof(char));
	*p = 0;
	h = p;
	while (!(c == 'p' && !n) && divisor > 0)
	{
		*h = (n / divisor % 16) + '0';
		*h += (*h > 57 && c == 'X') * 7 + (*h > 57 && c != 'X') * 39;
		h++;
		if (divisor == 1)
			divisor--;
		divisor /= 16;
	}
	return (p);
}

char	*printf_putnbr(int nmb, char c, char *p, int *i)
{
	char		*s;
	long int	n;
	long int	divisor;

	divisor = 1;
	*i = 1;
	if (nmb < 0 && c != 'u' && c != 'c')
		*(i + 4) = 1;
	n = (c == 'u' && nmb < 0) * 4294967296 + nmb;
	n = (n < 0) * -n + (n >= 0) * n;
	while (n / divisor > 9 && c != 'c')
	{
		divisor *= 10;
		*i += 1;
	}
	p = malloc(*i * sizeof(char));
	s = p;
	while (divisor > 0)
	{
		*s++ = ((n / divisor % 10) + 48) * (c != 'c') + nmb * (c == 'c');
		if (divisor == 1)
			divisor--;
		divisor /= 10;
	}		
	return (p);
}
