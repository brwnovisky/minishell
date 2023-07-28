/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:43:11 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/07/27 23:45:41 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		divisor;
	int		count;
	char	c;

	divisor = 1;
	count = 1;
	while (n / divisor > 9 || n / divisor < -9)
	{
		divisor *= 10;
		count++;
	}
	if (n < 0)
		write(fd, "-", 1);
	count += n < 0;
	while (divisor > 0)
	{
		c = (n / divisor % 10) * ((n >= 0) - (n < 0)) + '0';
		write(fd, &c, 1);
		if (divisor == 1)
			divisor--;
		divisor /= 10;
	}
}
