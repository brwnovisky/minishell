/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:42:06 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/08/13 18:32:11 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printer(char c, char *ptr, int *flags)
{
	while (flags[5]-- > 0)
		flags[0] += write(1, " ", 1);
	if (c != 'c' && c != 's')
	{
		if (flags[7] && c != 'u')
			flags[0] += write(1, "-", 1);
		else if (flags[43] && !flags[7])
			flags[0] += write(1, "+", 1);
		else if (flags[32] && !flags[7])
			flags[0] += write(1, " ", 1);
		if ((*ptr != '0' && c == 'x' && flags[35]) || (c == 'p' && *ptr))
			flags[0] += write(1, "0x", 2);
		else if (*ptr != '0' && c == 'X' && flags[35])
			flags[0] += write(1, "0X", 2);
		while (flags[4]-- > 0)
			flags[0] += write(1, "0", 1);
	}
	if (c == 's' && !ptr && !(flags[46] && flags[2] < flags[3]))
		flags[0] += write(1, "(null)", flags[3]);
	else if (c == 'p' && !*ptr)
		flags[0] += write(1, "(nil)", 5);
	else if (ptr)
		flags[0] += write(1, ptr, flags[3]);
	while (flags[6]-- > 0)
		flags[0] += write(1, " ", 1);
}

static void	ft_str_builder(char c, char *ptr, int *flags)
{
	if (flags[1] && !(c == 's' && flags[46]) && c != 'c' && c != 's')
	{
		if (!flags[2] || (flags[48] && !flags[45]))
		{
			flags[2] -= ((flags[32] || flags[43] || flags[7]) && (flags[48] && \
			!flags[45] && !flags[46]));
			flags[1] -= 2 * (c == 'p' && *ptr);
		}
		else if (flags[46])
			flags[1] -= 2 * ((c == 'x' || c == 'X') && flags[35]);
		if ((flags[46] || (flags[48] && !flags[45])) && c != 'p')
			flags[4] = (flags[2] > flags[3]) * (flags[2] - flags[3]);
	}
	flags[3] *= !(!flags[2] && flags[46] && flags[3] == 1 && *ptr == '0');
	flags[5 + (flags[45] > 0)] = flags[1] - (flags[4] + flags[3] + (flags[32] \
	|| flags[43] || flags[7]));
	flags[5 + (flags[45] > 0)] -= 4 * (c == 'p' && !*ptr);
	return (ft_printer(c, ptr, flags));
}

static char	*ft_arg_processor(va_list ap, char c, char *ptr, int *flags)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		ptr = printf_putnbr(va_arg(ap, int), c, ptr, flags + 3);
	else if (c == 's')
	{
		ptr = va_arg(ap, char *);
		while (ptr && ptr[flags[3]])
			flags[3]++;
		if (flags[46])
		{
			flags[3] = (flags[3] > flags[2]) * flags[2] + (flags[3] <= \
			flags[2]) * flags[3];
			flags[1] *= (flags[46] == 2);
		}
		flags[3] = 6 * !ptr + (ptr != NULL) * flags[3];
	}
	else if (c == 'p')
		ptr = printf_hex(va_arg(ap, unsigned long int), c, ptr, flags + 3);
	else if (c == 'x' || c == 'X')
		ptr = printf_hex(va_arg(ap, unsigned int), c, ptr, flags + 3);
	if (c == 'u' || c == 'x' || c == 'X' || c == 's')
	{
		flags[32] = 0;
		flags[43] = 0;
	}
	return (ptr);
}

static char	*ft_flag_colector(char *str, int *flags)
{
	flags[1] = 49;
	while (flags[1])
		flags[--flags[1]] = 0;
	while (*++str >= ' ' && *str <= '0' && *str != '%')
		*(flags + (*str)) = 1;
	while (*str >= '0' && *str <= '9')
	{
		flags[1] = flags[1] * 10 + *(str++) - '0';
		if (*str == '.')
		{
			flags[46] = 2;
			while (*++str >= '0' && *str <= '9')
				flags[2] = flags[2] * 10 + *str - '0';
		}
	}
	if (flags[46] == 1 || (flags[46] < 2 && flags[48] && !flags[45]))
		flags[2] = flags[1];
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		flags[49];
	char	*ptr;
	va_list	ap;

	flags[0] = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str - 1) != 92)
		{
			str = ft_flag_colector((char *)str, flags);
			ptr = ft_arg_processor(ap, *str, NULL, flags);
			if (*str != '%')
				ft_str_builder(*str, ptr, flags);
			else
				flags[0] += write(1, str, 1);
			if (*str != 's')
				free(ptr);
		}
		else
			flags[0] += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (flags[0]);
}
