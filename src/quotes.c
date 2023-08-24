/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:46:35 by root              #+#    #+#             */
/*   Updated: 2023/08/16 19:08:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	destroy_quote_list(t_block *current)
{
	t_quote	*current_quote;
	t_quote	*next_quote;

	current_quote = current->quotes_list;
	next_quote = current->quotes_list->next;
	while (current_quote)
	{
		safe_free(&current_quote);
		current_quote = next_quote;
		if (current_quote)
			next_quote = next_quote->next;
	}
	current->quotes_list = NULL;
	current->current_quote = NULL;
	current->quotes_n = 0;
}

void	ft_quotes_pair(char	**arg, t_quote *current_quote,
	enum e_quote quote_pair, char *arg_tmp)
{
	while (**arg)
	{
		if (quote_pair == QUOTE_CLOSE)
			current_quote = current_quote->next;
		quote_pair = (quote_pair != QUOTE_CLOSE) * quote_pair;
		if (!current_quote || **arg != current_quote->quote)
		{
			*arg_tmp = **arg;
			arg_tmp++;
		}
		else
			quote_pair += (**arg == current_quote->quote);
		(*arg)++;
	}
}

char	*quotes_clean(t_block *current, char **arg, char *a_free, int arg_len)
{
	char			*quote_clean;
	char			*arg_tmp;
	enum e_quote	quote_pair;
	t_quote			*current_quote;

	arg_len -= (current->quotes_n * 2);
	quote_clean = (char *)ft_calloc(arg_len + 1, sizeof(char));
	arg_tmp = quote_clean;
	current_quote = current->quotes_list;
	quote_pair = 0;
	ft_quotes_pair(arg, current_quote, quote_pair, arg_tmp);
	safe_free(&a_free);
	destroy_quote_list(current);
	current->quote_tmp = 0;
	return (quote_clean);
}

static void	quotes_update(t_block *current)
{
	current->quotes_n += 1;
	if (!current->current_quote)
	{
		current->current_quote = (t_quote *)ft_calloc(1, sizeof(t_quote));
		current->quotes_list = current->current_quote;
	}
	else if (current->current_quote && current->current_quote->quote)
	{
		current->current_quote->next = (t_quote *)ft_calloc(1, \
		sizeof(t_quote));
		current->current_quote = current->current_quote->next;
	}
	current->current_quote->quote = current->quote_tmp;
	current->quote_tmp = 0;
}

char	*is_quote(t_block *current, char *line)
{
	if (*line && (*line == CHAR_Q_SINGLE || *line == CHAR_Q_DOUBLE))
	{
		if (!current->quote_tmp)
			current->quote_tmp = *line;
		else if (*line == current->quote_tmp)
			quotes_update(current);
		line += 1;
	}
	return (line);
}
