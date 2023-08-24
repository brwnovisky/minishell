/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:05:26 by tasantos          #+#    #+#             */
/*   Updated: 2023/08/20 20:05:57 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	change_directory(char *new_path)
{
	char	*str_tmp;
	int		change_dir;

	str_tmp = new_path;
	change_dir = chdir(str_tmp);
	if (str_tmp && change_dir < 0)
	{
		str_tmp = ft_strjoin("/", str_tmp);
		change_dir = chdir(str_tmp);
		free (str_tmp);
	}
	return (change_dir);
}
