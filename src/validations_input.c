/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:53:49 by root              #+#    #+#             */
/*   Updated: 2023/08/15 20:11:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*is_command(t_shell **shell, t_block *current, char *line)
{
	char	*line_tmp;

	if (!line || !*line || current->set != COMMAND)
		return (line);
	current->set = TEST_HEREDOC;
	if (line != is_special(shell, current, line, STR_SPECIALS))
	{
		current->set = COMMAND;
		return (line);
	}
	current->set = COMMAND;
	line_tmp = is_no_word(shell, current, line);
	new_command(current);
	if (current->expand)
		current->current_command->arg = current->expand;
	else
		current->current_command->arg = ft_substr(line, 0, (line_tmp - line));
	if (current->quotes_list && current->quotes_list->quote)
		current->current_command->arg = quotes_clean(current, \
	&current->current_command->arg, current->current_command->arg, \
	ft_strlen(current->current_command->arg));
	current->expand = NULL;
	if (!current->commands->next)
		current->built_in = is_built_in(current->current_command->arg);
	return (line_tmp);
}

char	*is_file_io(t_shell **shell, t_block *current, char *line)
{
	char	*line_tmp;
	char	*file_name;

	if (!line || current->set < INFILE || current->set > OUTFILE_APPEND)
		return (line);
	line = is_spaces(line, STR_SPACES);
	line_tmp = is_no_word(shell, current, line);
	if (!line_tmp)
		return (NULL);
	if (current->expand)
		file_name = current->expand;
	else
		file_name = ft_substr(line, 0, (line_tmp - line));
	if (current->quotes_list && current->quotes_list->quote)
		file_name = quotes_clean(current, &file_name, file_name, \
		ft_strlen(file_name));
	current->expand = NULL;
	manage_file_descriptors(current, file_name);
	current->set = COMMAND;
	safe_free(&file_name);
	return (line_tmp);
}

char	*is_special(t_shell **shell, t_block *current, char *line, char *spcls)
{
	while (*spcls)
	{
		if (*line && *line != *spcls)
			spcls++;
		else if (!*line || *line == *spcls)
		{
			if (current->set != COMMAND)
				return (line + 1);
			return (special_cases(shell, current, line));
		}
	}
	return (line);
}

char	*is_spaces(char *line, char *spaces)
{
	while (line && *spaces)
	{
		if (*line != *spaces)
			spaces++;
		else if (*line == *spaces)
		{
			line++;
			spaces = STR_SPACES;
		}
	}
	return (line);
}

int	var_define(t_shell **shell, t_block *current, int arg_len)
{
	t_env	*var;

	if (current->arg_0[0] == CHAR_VAR && arg_len > 1)
	{
		var = find_var(shell, current->arg_0 + 1, arg_len - 1, 0);
		current->arg_0 = NULL;
		arg_len = 0;
		if (var)
			current->arg_0 = var->value;
		if (var && var->value)
			arg_len = ft_strlen(var->value);
	}
	return (arg_len);
}
