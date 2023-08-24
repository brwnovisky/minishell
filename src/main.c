/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:19:45 by root              #+#    #+#             */
/*   Updated: 2023/08/16 16:35:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	if (argc != 1 || argv[1] != NULL)
	{
		ft_printfd(ERROR_ARG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	make_env(&shell, envp, 0);
	minishell(&shell);
}
