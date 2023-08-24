/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:49:31 by root              #+#    #+#             */
/*   Updated: 2023/08/20 20:10:43 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*oldpwd_switch(t_shell **shell)
{
	t_env	*var;

	var = find_var(shell, "OLDPWD", 6, 0);
	if (var && var->value[0] != CHAR_SLASH)
	{
		printf("/%s\n", var->value);
		return (var->value);
	}
	else if (var)
	{
		printf("%s\n", var->value);
		return (var->value);
	}
	else
	{
		ft_printfd(ERROR_CD2, STDERR_FILENO);
		return (NULL);
	}
}

int	returned_error(t_shell **shell, int error)
{
	if (error)
	{
		(*shell)->exit_code = 1;
		return (TRUE);
	}
	return (FALSE);
}

void	export_two(t_shell **shell, char *old_path)
{
	char	buf[BUF];

	export_var(shell, "OLDPWD", old_path);
	export_var(shell, "PWD", getcwd(buf, BUF));
	return ;
}

int	conditions_if(t_shell **shell)
{
	if ((*shell)->pipelist->commands_n == 1
		|| strchr_mod((*shell)->pipelist->args[1], CHAR_TILDE))
		return (TRUE);
	return (FALSE);
}

void	c_cd(t_shell **shell)
{
	char	buf[BUF];
	char	*new_path;
	char	*old_path;
	int		error;

	error = 0;
	old_path = getcwd(buf, BUF);
	new_path = NULL;
	if ((*shell)->pipelist->commands_n == 2)
		new_path = (*shell)->pipelist->args[1];
	if ((*shell)->pipelist->commands_n > 2 && ++error)
		ft_printfd(ERROR_CD1, STDERR_FILENO);
	else if (conditions_if(shell))
		new_path = (find_var(shell, "HOME", 4, 0))->value;
	else if ((*shell)->pipelist->args[1]
		&& (*shell)->pipelist->args[1][0] == CHAR_MINUS)
	{
		new_path = oldpwd_switch(shell);
		error += (new_path == NULL);
	}
	if (new_path && change_directory(new_path) < 0)
		ft_printfd(ERROR_CD3, STDERR_FILENO, new_path);
	if (returned_error(shell, error))
		return ;
	export_two(shell, old_path);
}
