/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:34 by root              #+#    #+#             */
/*   Updated: 2023/08/17 19:31:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	verify_num(char *str)
{
	str += (*str == CHAR_MINUS || *str == CHAR_PLUS);
	while (*str && ft_isdigit(*str))
		str++;
	if (!*str)
		return (FALSE);
	else
		return (2);
}

void	c_exit(t_shell **shell)
{
	u_int8_t	exit_code;

	exit_code = EXIT_SUCCESS;
	if ((*shell)->pipelist->commands_n > 2)
	{
		ft_printfd(ERROR_EXIT, STDERR_FILENO, NAME_EXIT);
		exit_code = EXIT_FAILURE;
	}
	if ((*shell)->pipelist->commands_n == 2)
	{
		exit_code = verify_num((*shell)->pipelist->args[1]);
		if (!exit_code)
			exit_code = ft_atoi64((*shell)->pipelist->args[1]);
		if (exit_code == 2)
			ft_printfd(ERROR_EXIT1, STDERR_FILENO, (*shell)->pipelist->args[1]);
	}
	printf("exit\n");
	free_shell(shell);
	exit(exit_code);
	return ;
}
