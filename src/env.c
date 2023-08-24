/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:49:18 by root              #+#    #+#             */
/*   Updated: 2023/08/16 16:35:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_env	*find_var(t_shell **shell, char *key, int key_len, int is_unset)
{
	t_env	*current_var;

	current_var = (*shell)->env;
	while (current_var)
	{
		if ((is_unset && current_var->next && \
		key_len == (int)ft_strlen(current_var->next->key) \
		&& !ft_strncmp(current_var->next->key, key, key_len)) \
		|| (!is_unset && key_len == (int)ft_strlen(current_var->key) \
		&& !ft_strncmp(current_var->key, key, key_len)))
			return (current_var);
		current_var = current_var->next;
	}
	return (NULL);
}

void	print_env(t_shell **shell, int is_export)
{
	t_env	*current;

	current = (*shell)->env;
	while (current)
	{
		if (is_export)
			printf("declare -x ");
		if (is_export || (!is_export && current->value && *current->value))
			printf("%s", current->key);
		if ((is_export || !is_export) && current->value && *current->value)
			printf("=");
		if (is_export && current->value)
			printf("\"");
		if (current->value && *current->value)
			printf("%s", current->value);
		if (is_export && current->value)
			printf("\"");
		if (is_export || (!is_export && current->value && *current->value))
			printf("\n");
		current = current->next;
	}
}

void	c_env(t_shell **shell)
{
	return (print_env(shell, 0));
}

void	make_env(t_shell **shell, char **envp, int str_len)
{
	t_env	*env_node;
	char	*equal_position;

	(*shell)->env = (t_env *)ft_calloc(1, sizeof(t_env));
	env_node = (*shell)->env;
	while (*envp)
	{
		(*shell)->env_n += 1;
		equal_position = ft_strchr(*envp, '=');
		str_len = equal_position - *envp;
		env_node->key = ft_substr(*envp, 0, str_len);
		str_len = ft_strlen(++equal_position);
		env_node->value = ft_substr(equal_position, 0, str_len);
		(*shell)->env_last = env_node;
		if (!*++envp)
			break ;
		env_node->next = (t_env *)ft_calloc(1, sizeof(t_env));
		env_node = env_node->next;
	}
}
