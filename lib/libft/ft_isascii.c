/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:13:54 by bluiz-al          #+#    #+#             */
/*   Updated: 2022/06/02 00:35:03 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{	
	return (c == (unsigned char) c && c < 128);
}