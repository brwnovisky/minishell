/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:34 by root              #+#    #+#             */
/*   Updated: 2023/07/19 09:18:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void remove_variable(t_env **list, char *var)
{
	t_env	*temp;

	temp = *list;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		if (!strcmp_mod(temp->var, var))
		{
			if (temp->prev == NULL)
			{
				*list = temp->next;
				if (temp->next)
					temp->next->prev = NULL;
			}
			else if (temp->next == NULL)
				temp->prev->next = NULL;
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			free(temp->var);
			free(temp->msg);
			free(temp);
			return ;
		}
		temp = temp->next;
	}
}

// void	c_unset(t_shell **shell)
// {
// 	shell = (shell);
// 	if (!strcmp_mod((*shell)->command, "unset"))
// 	{
// 		apart_args(shell, ' ', exe_unset);
// 	}
// }

// void	exe_unset(t_shell **shell)
// {
// 	if ((*shell)->content)
// 	{
// 		return ;
// 	}
// }

void	c_unset(t_shell **shell)
{
	if (is_var(shell, (*shell)->pipelist->commands->next->arg))
		remove_variable(&(*shell)->env, (*shell)->pipelist->commands->next->arg);
	(*shell)->exit_code = 0;
}
