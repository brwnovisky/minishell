/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:02:11 by root              #+#    #+#             */
/*   Updated: 2023/08/20 20:35:51 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	export_new_var(t_shell **shell, char *key, char *value)
{
	t_env	*new_var;
	int		value_len;

	new_var = (t_env *)ft_calloc(1, sizeof(t_env));
	(*shell)->env_last->next = new_var;
	(*shell)->env_last = new_var;
	new_var->key = ft_substr(key, 0, ft_strlen(key));
	if (value)
	{
		value_len = ft_strlen(value);
		if (value_len == 1 && value[0] == '=')
			value[0] = 1;
		else
			value += 1;
		new_var->value = ft_substr(value, 0, ft_strlen(value));
	}
	(*shell)->env_n += 1;
}

static int	is_valid_key(char *arg)
{
	if (!ft_isdigit(*arg))
	{
		while (*arg && (ft_isalnum(*arg) || (*arg == '_')))
			arg++;
		if (!*arg)
			return (TRUE);
	}	
	return (FALSE);
}

int	is_pipelined(t_shell **shell)
{
	if ((*shell)->current->commands_n > 1 && (*shell)->pipelist_n > 1)
	{
		(*shell)->exit_code = 1;
		return (TRUE);
	}
	return (FALSE);
}

void	else_matter(t_shell **shell, char *key)
{
	(*shell)->exit_code = 1;
	ft_printfd(ERROR_EXPORT, STDERR_FILENO, key);
}

void	c_export(t_shell **shell)
{
	t_cmd	*current;
	char	*key;
	char	*value;

	if (is_pipelined(shell))
		return ;
	if ((*shell)->current->commands_n == 1)
		return (print_env(shell, 1));
	current = (*shell)->pipelist->commands->next;
	while (current && current->arg)
	{
		value = ft_strchr(current->arg, '=');
		if (value && value != current->arg)
			key = ft_substr(current->arg, 0, (value - current->arg));
		else
			key = ft_substr(current->arg, 0, ft_strlen(current->arg));
		if (is_valid_key(key))
			export_var(shell, key, value);
		else
			else_matter(shell, key);
		safe_free(&key);
		current = current->next;
	}
}
