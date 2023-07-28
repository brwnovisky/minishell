/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:46:35 by root              #+#    #+#             */
/*   Updated: 2023/07/15 20:49:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*is_quote(t_cmd *current_command, char *line)
{
	if (*line == '\'' || *line == '\"')
	{
		line += 1;
		while (*line != current_command->quote)
		{

			line += 1;
		}
	}
	return (line);
}
