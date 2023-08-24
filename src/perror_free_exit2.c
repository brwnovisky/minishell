/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_free_exit2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:06:08 by root              #+#    #+#             */
/*   Updated: 2023/08/20 20:52:16 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_around(t_block *current_cmd)
{
	t_cmd	*next_cmd;
	t_cmd	*current;

	current = current_cmd->commands;
	while (current)
	{
		next_cmd = current->next;
		safe_free(&current);
		current = next_cmd;
	}
}

void	free_pipe_list(t_shell **shell, t_block *current)
{
	t_block	*next;
	t_cmd	*current_cmd;

	if (current)
		current_cmd = current->commands;
	else
		return ;
	if (current_cmd && current->cmd != current_cmd->arg)
		safe_free(&current->cmd);
	(*shell)->pipelist_n = 0;
	(*shell)->previous = NULL;
	while (current)
	{
		free_args_matrix(current, current->args);
		safe_free(&current->args);
		if (current->heredoc_name)
			unlink(current->heredoc_name);
		safe_free(&current->heredoc_name);
		if (current_cmd)
			free_around(current);
		next = current->next;
		safe_free(&current);
		(*shell)->pipelist = NULL;
		current = next;
	}
}
