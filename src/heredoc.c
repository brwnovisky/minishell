/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:30 by root              #+#    #+#             */
/*   Updated: 2023/08/20 20:51:12 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	wait_heredoc_child(t_shell **shell, int pid)
{
	int	status;

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
		exit (SIGINT_HD);
}

void	heredoc_name_setup(t_shell **shell, t_block *current)
{
	char	*name;
	int		len;

	if (!(*shell)->heredoc_name)
		(*shell)->heredoc_name = ft_substr(STR_HEREDOC, 0, 4);
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
		current->fd[0] = open(current->heredoc_name, O_CREAT | O_RDWR, CHMOD);
		signal_listener(SIG_IGN, heredoc_sigint);
		while (TRUE)
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

	line = is_spaces(line, STR_SPACES);
	line_tmp = is_no_word(shell, current, line);
	if (!line_tmp)
		return (NULL);
	line_diff = line_tmp - line;
	delimiter = ft_substr(line, 0, line_diff);
	if (current->quotes_list && current->quotes_list->quote)
		delimiter = quotes_clean(current, &delimiter, delimiter, \
		ft_strlen(delimiter));
	heredoc_name_setup(shell, current);
	here_doc_exec(shell, current, delimiter);
	current->set = COMMAND;
	current->fd[0] = open(current->heredoc_name, O_RDONLY);
	return (line + line_diff);
}
