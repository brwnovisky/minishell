/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_input2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:49 by root              #+#    #+#             */
/*   Updated: 2023/08/17 19:19:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_parent_builtins(void *builtin, int commands_n)
{
	if ((builtin == c_export && commands_n > 1) || builtin == c_unset \
	|| builtin == c_exit || builtin == c_cd)
		return (TRUE);
	return (FALSE);
}

int	command_validate(t_shell **shell, t_block *current)
{
	char	*cmd_tmp;
	char	*cmd_tmp2;
	int		i;

	i = -1;
	while (*current->cmd && ++i < (*shell)->paths_n)
	{
		cmd_tmp = ft_strjoin((*shell)->paths_mtx[i], STR_SLASH);
		cmd_tmp2 = ft_strjoin(cmd_tmp, current->cmd);
		safe_free(&cmd_tmp);
		if (!(access(current->args[0], X_OK)) || !(access(cmd_tmp2, X_OK)))
		{
			if (!(access(current->args[0], X_OK)))
				current->cmd = ft_strdup(current->args[0]);
			else
				current->cmd = cmd_tmp2;
			return (SUCCES);
		}
		else
			safe_free(&cmd_tmp2);
	}
	ft_printfd(ERROR_CMD, STDERR_FILENO, current->cmd);
	(*shell)->exit_code = 127;
	return (EXCEPTION);
}

static int	is_io_valid_token(int set, char line, char *newline, char *str_void)
{
	if (set >= 2 && set <= 4 && (!line || ft_strchr(STR_SPECIALS, line)))
	{
		if (!line)
			line = 1;
		else
			newline = str_void;
		ft_printfd(ERROR_IO_CHAR, STDERR_FILENO, newline, line);
		return (EXCEPTION);
	}
	return (SUCCES);
}

char	*is_no_word(t_shell **shell, t_block *current, char *line)
{
	if (is_io_valid_token(current->set, *line, STR_NEWLINE, STR_VOID))
		return (NULL);
	current->arg_0 = line;
	while (line == is_special(shell, current, line, STR_SPECIALS))
	{
		if (current->set != TEST_HEREDOC && line != is_quote(current, line))
		{
			is_var(shell, current, line, 0);
			while (*++line != current->quote_tmp && *line)
				is_var(shell, current, line, 0);
			is_quote(current, line);
		}
		is_var(shell, current, line, 0);
		if (!*line || line != is_spaces(line, STR_SPACES))
			break ;
		line++;
	}
	return (line);
}
