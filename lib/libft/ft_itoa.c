/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:48:06 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/23 23:48:02 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		divisor;
	int		count;

	divisor = 1;
	count = 1;
	while (n / divisor > 9 || n / divisor < -9)
	{
		divisor *= 10;
		count++;
	}
	str = ft_calloc(count + 1 + (n < 0), sizeof(char));
	if (n < 0)
		str[0] = '-';
	count = n < 0;
	while (divisor > 0)
	{
		str[count++] = (n / divisor % 10) *((n >= 0) - (n < 0)) + '0';
		if (divisor == 1)
			divisor--;
		divisor /= 10;
	}
	return (str);
}
