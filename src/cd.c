/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:49:31 by root              #+#    #+#             */
/*   Updated: 2023/07/15 19:49:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	update_var(t_shell **shell, char *name, char *value)
{
	char	*env;

	env = NULL;
	if (env && shell && name)
	{
		free(env);
		env = ft_strdup(value);
	}
}

// void	c_cd(t_shell **shell)
// {
// 	char	*var;
// 	char	*oldpwd;
// 	char	buf[256];

// 	shell = (shell);
// 	var = NULL;
// 	if (!is_flag_null(shell, ""))
// 		return ;
// 	if (!(*shell)->content && !(*shell)->flag)
// 		(*shell)->content = getenv("HOME");
// 	else if (!strcmp_mod((*shell)->flag, "-"))
// 	{
// 		(*shell)->content = var;
// 		printf("%s\n", (*shell)->content);
// 	}
// 	oldpwd = var;
// 	if (chdir((*shell)->content) != 0)
// 		printf("bash: cd: %s: No such file or directory\n", 
// 		(*shell)->content);
// 	else
// 	{
// 		rl_redisplay();
// 		update_var(shell, "OLDPWD", oldpwd);
// 		update_var(shell, "PWD", getcwd(buf, 256));
// 	}
// }
