/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_free_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:24:21 by root              #+#    #+#             */
/*   Updated: 2023/08/15 20:06:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	safe_free(void *pointer)
{
	if (pointer != NULL)
		free(*((void **)pointer));
	*((void **)pointer) = NULL;
}

void	free_quote_list(t_block *current)
{
	t_quote	*current_quote_pair;
	t_quote	*next_quote_pair;

	current_quote_pair = current->quotes_list;
	if (current->quotes_list)
		next_quote_pair = current->quotes_list->next;
	while (current_quote_pair)
	{
		safe_free(&current_quote_pair);
		current_quote_pair = next_quote_pair;
		if (current_quote_pair)
			next_quote_pair = current_quote_pair->next;
	}
}

static void	free_env(t_shell **shell)
{
	t_env	*current_env;
	t_env	*next_env;

	current_env = (*shell)->env;
	next_env = (*shell)->env->next;
	while (current_env)
	{
		safe_free(&current_env->key);
		safe_free(&current_env->value);
		safe_free(&current_env);
		current_env = next_env;
		if (current_env)
			next_env = current_env->next;
	}
}

void	free_shell(t_shell **shell)
{
	rl_clear_history();
	free_execve_env_matrix(shell);
	free_pipe_list(shell, (*shell)->pipelist);
	free_env(shell);
	safe_free(shell);
}

void	free_args_matrix(t_block *current, char **args)
{
	int	count;

	count = 0;
	while (args && ++count <= current->commands_n)
		safe_free(args++);
}
