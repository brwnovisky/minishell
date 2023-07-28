/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:28 by macarval          #+#    #+#             */
/*   Updated: 2023/07/19 07:56:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	manage_file_descriptors(t_block *current, char *file_name)
{
	if (current->set == 2 && current->fd[0])
		close(current->fd[0]);
	else if (current->set >= 3 && current->fd[1])
		close(current->fd[1]);
	if (current->set == 2)
		current->fd[0] = open(file_name, O_RDONLY, 0644);
	else if (current->set == 3)
		current->fd[1] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (current->set == 4)
		current->fd[1] = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
}

char	*special_cases(t_shell **shell, t_block *current, char *line)
{
	if (*line == '<' && *++line)
	{
		current->set = 2;
		if (*line == '<' && *++line)
			return (here_doc_setup(shell, current, line));
	}
	else if (*line == '>' && *++line)
	{
		current->set = 3;
		if (*line == '>' && *++line)
			current->set = 4;
	}
	else if (*line == '|' && line++)
			current->set = 0;
	return (line);
}

int	find(char *string1, char c)
{
	int		i;

	i = ft_strlen(string1);
	while (i >= 0)
	{
		if (string1[i] == c)
			return (1);
		i--;
	}
	return (0);
}

void	minishell(t_shell **shell)
{
	char	*line;

	signal_listener(SIG_IGN, handle_sigint);
	while (1)
	{
		line = readline("minishell $> ");
		(*shell)->exit_code = 0;
		if (line && *line)
		{
			needs_env_update(shell, (*shell)->env, (*shell)->env_n);
			add_history(line);
			pipe_list_build(shell, line);
			execution(shell, (*shell)->pipelist);
			free_pipe_list((*shell)->pipelist);
		}
		else if (line == NULL)
			handle_sigquit(shell);
	}
}
