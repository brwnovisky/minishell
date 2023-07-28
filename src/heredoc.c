/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:30 by root              #+#    #+#             */
/*   Updated: 2023/07/15 20:22:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void wait_heredoc_child(t_shell **shell, int pid)
{
	int status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
			(*shell)->exit_code = WEXITSTATUS(status);
}


void	heredoc_sigint(int signal)
{
	ft_putendl_fd("", 1);
	rl_replace_line("", 0);
	rl_done = 1;
	close(rl_instream->_fileno);
	if (signal)
		exit(1);
}

void	heredoc_name_setup(t_shell **shell, t_block *current)
{
	char	*name;
	int		len;

	if (!(*shell)->heredoc_name)
		(*shell)->heredoc_name = ft_substr(HEREDOCNAME, 0, 4);
	else if ((*shell)->heredoc_name)
	{
		name = (*shell)->heredoc_name;
		len = ft_strlen(name);
		(*shell)->heredoc_name = (char *)ft_calloc(len + 2, sizeof(char));
		ft_strlcpy((*shell)->heredoc_name, name, len + 1);
		(*shell)->heredoc_name[len] = 1; 
	}
	current->heredoc_name = (*shell)->heredoc_name;
}

void	here_doc_exec(t_shell **shell, t_block *current, char *delimiter)
{
	char	*user_input;
	int		user_input_len;
	int		child;

	child = fork();
	if (!child)
	{
		current->fd[0] = open(current->heredoc_name, O_CREAT | O_RDWR, 0644);
		signal_listener(SIG_IGN, heredoc_sigint);
		while (1)
		{
			user_input = readline("> ");
			user_input_len = ft_strlen(user_input);
			if (!user_input || !strcmp_mod(user_input, delimiter))
				break ;
			write(current->fd[0], user_input, user_input_len);
			write(current->fd[0], "\n", 1);
		}
		close(current->fd[0]);
		exit(0);
	}
	wait_heredoc_child(shell, child);
}

char	*here_doc_setup(t_shell **shell, t_block *current, char *line)
{
	char	*line_tmp;
	int		line_diff;
	char	*delimiter;

	current->set = 3;
	line = is_spaces(line, SPACES);
	line_tmp = line;
	line_tmp = is_no_word(shell, current, line_tmp);
	current->set = 1;
	line_diff = line_tmp - line;
	delimiter = ft_substr(line, 0, line_diff);
	here_doc_exec(shell, current, delimiter);
	current->fd[0] = open(current->heredoc_name, O_RDONLY);
	return (line + line_diff);
}
