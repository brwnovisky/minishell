/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:00:04 by root              #+#    #+#             */
/*   Updated: 2023/08/15 20:01:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	signal_set(int signal)
{
	g_signal = signal;
}

void	signal_listener(__sighandler_t handle_quit, __sighandler_t handle_int)
{
	g_signal = 0;
	if (handle_quit)
		signal(SIGQUIT, handle_quit);
	if (handle_int)
		signal(SIGINT, handle_int);
}

void	handle_sigquit(t_shell **shell)
{
	int8_t	exit_code;

	exit_code = (*shell)->exit_code;
	ft_putstr_fd("exit\n", 1);
	free_shell(shell);
	exit(exit_code);
}

void	handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = 128 + 2;
	}
}

void	signal_handled_exec(t_shell **shell)
{
	signal_listener(NULL, signal_set);
	if (shell)
		shell = NULL;
}
