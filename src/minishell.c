/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:02:28 by root              #+#    #+#             */
/*   Updated: 2023/08/16 20:03:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	minishell(t_shell **shell)
{
	char	*line;

	signal_listener(SIG_IGN, handle_sigint);
	while (TRUE)
	{
		line = readline(COLOR_BHCYAN "MiniShell" COLOR_BHRED "$" \
		COLOR_BHCYAN "> " COLOR_RESET);
		if (line && *line)
		{
			add_history(line);
			pipe_list_build(shell, line);
			execution(shell, &(*shell)->current);
			free_pipe_list(shell, (*shell)->pipelist);
		}
		else if (line == NULL)
		{
			safe_free(&line);
			handle_sigquit(shell);
		}
		safe_free(&line);
	}
}
