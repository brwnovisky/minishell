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

void	previous_var(t_shell **shell, t_env *var_prev)
{
	t_env	*var_target;

	var_target = var_prev->next;
	var_prev->next = var_target->next;
	if (var_prev->next == NULL)
		(*shell)->env_last = var_prev;
	safe_free(&var_target->key);
	safe_free(&var_target->value);
	safe_free(&var_target);
	(*shell)->env_n -= 1;
}

void	c_unset(t_shell **shell)
{
	t_cmd	*current;
	t_env	*var_prev;

	current = (*shell)->pipelist->commands->next;
	if (!current || (current && current->arg[0] == CHAR_MINUS))
	{
		if (current == NULL)
			return ;
		if (current->arg[0] == CHAR_MINUS)
			ft_printfd(ERROR_OPTION, STDERR_FILENO, NAME_UNSET);
		return ;
	}
	while (current && current->arg)
	{
		var_prev = find_var(shell, current->arg, ft_strlen(current->arg), 1);
		if (var_prev)
			previous_var(shell, var_prev);
		current = current->next;
	}
}
