/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:46:47 by root              #+#    #+#             */
/*   Updated: 2023/07/15 21:05:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_split(char ***split)
{
	int		i;
	char	**temp;

	i = -1;
	temp = *split;
	while (temp[++i])
		free(temp[i]);
	free(*split);
}

t_env	*find_arg(t_shell **shell, char *var)
{
	t_env	*temp;

	temp = (*shell)->env;
	while (temp != NULL)
	{
		if (!strcmp_mod(temp->var, var))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

// int	is_args(t_shell **shell)
// {
// 	if ((*shell)->content[0] == '=' || ft_isdigit((*shell)->content[0]))
// 	{
// 		printf("bash: %s: `%s': not a valid identifier\n", 
// 		(*shell)->command, (*shell)->content);
// 		return (0);
// 	}
// 	return (1);
// }

// void	apart_args(t_shell **shell, char c, void (*function)(t_shell **shell))
// {
// 	int		i;
// 	char	**split;

// 	i = -1;
// 	split = ft_split((*shell)->content, c);
// 	while (split[++i])
// 	{
// 		(*shell)->content = split[i];
// 		function(shell);
// 	}
// 	free_split(&split);
// }

void	args_matrix(t_block *current)
{
	t_cmd	*current_cmd;
	char	*arg_tmp;
	int		index;
	int		is_cmd;

	if (!current->commands)
		return ;
	is_cmd = 0;
	index = -1;
	current_cmd = current->commands;
	current->args = (char **)ft_calloc(current->commands_n + 1, sizeof(char *));
	while (current_cmd && index < current->commands_n)
	{
		is_cmd += (!strchr_mod(current_cmd->arg, '='));
		if (is_cmd)
		{
			arg_tmp = ft_strtrim(current_cmd->arg, &current->commands->quote);
			if (!index)
				current->cmd = arg_tmp;
			current->args[index] = arg_tmp;
			index += 1;
		}
		else	
		current_cmd = current_cmd->next;
	}
	current->args[index + 1] = NULL;
}
