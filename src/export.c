/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:02:11 by root              #+#    #+#             */
/*   Updated: 2023/07/17 11:18:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_export(t_shell **shell)
{
	while (*shell != NULL)
	{
		/*
		// Colocar em ordem alfabética
		*/
		// if ((*shell)->env_in->type != LOCAL)
		// {
		// 	printf("declare -x %s", (*shell)->env_in->var);
		// 	if ((*shell)->env_in->msg)
		// 		printf("=\"%s\"", (*shell)->env_in->msg);
		// 	printf("\n");
		// }
		// (*shell)->env_in = (*shell)->env_in->next;
	}
}

void	c_export(t_shell **shell)
{
	shell = (shell);
// 	if (!strcmp_mod((*shell)->command, "export"))
// 	{
// 		if (!is_flag_null(shell, ""))
// 			return ;
// 		if (!(*shell)->content)
// 			print_export(shell);
// 		else
// 			apart_args(shell, ' ', add_export);
// 	}
}

// void	add_export(t_shell **shell)
// {
// 	if (!is_args(shell))
// 		return ;
// }
