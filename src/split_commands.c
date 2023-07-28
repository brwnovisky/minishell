/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:21 by root              #+#    #+#             */
/*   Updated: 2023/07/15 21:32:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	**ft_mtx(t_shell **shell, char *s, char *c, char **mtx)
{
	char	*p;
	char	*p_chr;

	p = s;
	p_chr = p;
	(*shell)->count = 0;
	while (p_chr && p && *p && *p_chr)
	{	
		if (p_chr && *p_chr)
			p = p_chr;
		while (p_chr && *p && *p == *c && *c)
			p++;
		p_chr = ft_strchr(p, *c);
		(*shell)->count += (*p && *p != *c);
		if (p && *p && mtx != NULL)
			mtx[(*shell)->count - 1] = ft_substr(p, 0, p_chr - p);
	}
	if (mtx == NULL)
	{
		mtx = (char **)ft_calloc((*shell)->count + 1, sizeof(char *));
		return (ft_mtx(shell, s, c, mtx));
	}
	mtx[(*shell)->count] = 0;
	return (mtx);
}

char	**split_commands(t_shell **shell, char *s, char c)
{
	return (ft_mtx(shell, s, &c, NULL));
}

void	new_command(t_block *current)
{
	current->commands_n += 1;
	if (!current->current_command)
	{
		current->current_command = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		current->commands = current->current_command;
	}
	else if (current->commands)
	{
		current->current_command->next = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		current->current_command = current->current_command->next;
	}
}
