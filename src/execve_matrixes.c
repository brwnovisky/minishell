/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:09:59 by root              #+#    #+#             */
/*   Updated: 2023/07/15 21:32:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_execve_env_matrix(t_shell **shell)
{
	char	**env_matrix_tmp;
	char	**path_matrix_tmp;
	int		count;

	count = 0;
	env_matrix_tmp = (*shell)->env_mtx;
	path_matrix_tmp = (*shell)->paths_mtx;
	while (env_matrix_tmp && ++count <= (*shell)->env_n)
	{
		if (env_matrix_tmp && count <= (*shell)->paths_n)
			safe_free(&*path_matrix_tmp);
		safe_free(&*env_matrix_tmp);
		path_matrix_tmp++;
		env_matrix_tmp++;
	}
	safe_free(&(*shell)->env_mtx);
	safe_free(&(*shell)->paths_mtx);
}

static void	execve_path_matrix(t_shell **shell, t_env *current)
{
	if (!strcmp_mod("PATH", current->key))
	{
		(*shell)->paths_mtx = split_commands(shell, current->value, ':');
		(*shell)->paths_n = (*shell)->count;
	}
}

static void	execve_env_matrix(t_shell **shell, t_env *current_env, int env_n)
{
	char	**env_mtx;
	int		key_len;
	int		value_len;

	if ((*shell)->env && (*shell)->paths_mtx)
		free_execve_env_matrix(shell);
	(*shell)->env_mtx = (char **)ft_calloc(env_n + 1, sizeof(char *));
	env_mtx = (*shell)->env_mtx;
	while (current_env)
	{
		execve_path_matrix(shell, current_env);
		key_len = strlen(current_env->key);
		value_len = ft_strlen(current_env->value);
		*env_mtx = (char *)ft_calloc(key_len + value_len + 2, sizeof(char));
		ft_strlcpy(*env_mtx, current_env->key, key_len + 1);
		ft_strlcpy(*env_mtx + key_len, "=", 2);
		if (value_len)
			ft_strlcpy(*env_mtx + key_len + 1, current_env->value, \
			value_len + 1);
		*(*env_mtx + key_len + value_len + 1) = 0;
		current_env = current_env->next;
		env_mtx++;
	}
	env_mtx = NULL;
}

void	execve_matrixes(t_shell **shell, t_block *current)
{
	t_cmd	*current_cmd;
	int		index;

	if (!current->commands)
		return ;
	index = 0;
	current_cmd = current->commands;
	current->args = (char **)ft_calloc(current->commands_n + 1, sizeof(char *));
	while (current_cmd && index < current->commands_n)
	{
		if (!index)
			current->cmd = current_cmd->arg;
		current->args[index] = current_cmd->arg;
		index += 1;
		current_cmd = current_cmd->next;
	}
	current->args[index] = NULL;
	if (!current->built_in)
		execve_env_matrix(shell, (*shell)->env, (*shell)->env_n);
}
