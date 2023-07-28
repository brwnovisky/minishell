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

#include "../headers/minishell.h"

void	free_env_mtx(char **env, int env_n, char **paths, int paths_n)
{
	char	**env_tmp;
	int		idx;

	idx = -1;
	env_tmp = env;
	while (++idx < env_n)
	{
		safe_free((void **)&*env_tmp);
		env_tmp++;
	}
	safe_free((void **)&env);
	idx = -1;
	env_tmp = paths;
	while (++idx < paths_n)
	{
		safe_free((void **)&*env_tmp);
		env_tmp++;
	}
	safe_free((void **)&paths);
}

void	env_mtx_update(t_shell **shell, t_env *current, int env_n)
{
	char	**env_mtx;
	int		var_len;
	int		msg_len;

	if ((*shell)->env && (*shell)->paths_mtx)
		free_env_mtx((*shell)->env_mtx,
			env_n, (*shell)->paths_mtx, (*shell)->paths_n);
	(*shell)->env_mtx = (char **)ft_calloc(env_n + 1, sizeof(char *));
	env_mtx = (*shell)->env_mtx;
	while (current)
	{
		if (!strcmp_mod("PATH", current->var))
			(*shell)->paths_mtx = split_commands(shell, current->msg, ':');
		(*shell)->paths_n = (*shell)->count;
		var_len = strlen(current->var);
		msg_len = strlen(current->msg);
		*env_mtx = (char *)ft_calloc(var_len + msg_len + 2, sizeof(char));
		ft_strlcpy(*env_mtx, current->var, var_len + 1);
		ft_strlcpy(*env_mtx + var_len, "=", 2);
		ft_strlcpy(*env_mtx + var_len + 1, current->msg, msg_len + 1);
		*(env_mtx + var_len + msg_len) = '\0';
		current = current->next;
		env_mtx++;
	}
	env_mtx = NULL;
}

void	needs_env_update(t_shell **shell, t_env *current, int env_n)
{
	int	needs;

	needs = 0;
	needs += ((*shell)->env_mtx == NULL);
	if ((*shell)->pipelist)
	{
		// needs += ((*shell)->pipelist->built_in == (void *)c_export);
		// needs += ((*shell)->pipelist->built_in == (void *)c_unset);
	}
	if (needs)
		env_mtx_update(shell, current, env_n);
}

int	is_var(t_shell **shell, char *var)
{
	t_env	*temp;

	temp = (*shell)->env;
	while (temp != NULL)
	{
		if (!strcmp_mod(temp->var, var))
			return (1);
		temp = temp->next;
	}
	return (0);
}
