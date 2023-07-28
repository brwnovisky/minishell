/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:00:04 by root              #+#    #+#             */
/*   Updated: 2023/07/15 20:29:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	signal_set(int signal)
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
	ft_putstr_fd("exit\n", 1);
	rl_clear_history();
	exit((*shell)->exit_code);
}

void	handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = 130;
	}
}

void	signal_handled_exec(t_shell **shell)
{
	signal_listener(NULL, signal_set);
	if (shell)
		shell = NULL;
}

