/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_input3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:11:06 by root              #+#    #+#             */
/*   Updated: 2023/08/20 20:14:19 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	double_safe_free(char **str1, char **str2)
{
	safe_free(str1);
	safe_free(str2);
}

int	conditions_verify(t_block *current, char *arg)
{
	if (*arg == CHAR_VAR || (current->expand && (!*arg || *arg == CHAR_EQUAL \
	|| arg != is_spaces(arg, STR_SPACES) || *arg == CHAR_Q_DOUBLE \
	|| *arg == CHAR_QUESTION)))
		return (TRUE);
	return (FALSE);
}

void	is_var(t_shell **shell, t_block *current, char *arg, int arg_len)
{
	char	*expand_tmp;

	expand_tmp = NULL;
	if (current->set == TEST_HEREDOC || current->quote_tmp == CHAR_Q_SINGLE)
		return ;
	if (conditions_verify(current, arg))
	{
		if (current->arg_0[0] == CHAR_VAR && *arg == CHAR_QUESTION)
		{
			current->arg_0 = ft_itoa((*shell)->exit_code);
			expand_tmp = current->arg_0;
			arg_len = ft_strlen(current->arg_0);
			arg++;
		}
		else
			arg_len = var_define(shell, current, (arg - current->arg_0));
		current->arg_0 = ft_substr(current->arg_0, 0, arg_len);
		if (expand_tmp)
			safe_free(&expand_tmp);
		expand_tmp = current->expand;
		current->expand = ft_strjoin(current->expand, current->arg_0);
		double_safe_free(&current->arg_0, &expand_tmp);
		current->arg_0 = arg;
	}
}
