/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:03 by macarval          #+#    #+#             */
/*   Updated: 2023/07/17 11:23:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_args_echo(t_cmd *list)
{
	t_cmd	*temp;
	char	*cmd;
	char	*flag;

	flag = "-n";
	cmd = "echo";
	temp = list;
	while (temp != NULL)
	{
		if (!strcmp_mod(temp->arg, cmd))
			temp = temp->next;
		else if (!strcmp_mod(temp->arg, flag))
			temp = temp->next;
		else if (temp->next != NULL)
		{
			printf("%s ", temp->arg);
			temp = temp->next;
		}
		else
		{
			printf("%s", temp->arg);
			temp = temp->next;
		}
	}
}

// char	*flag_echo(t_shell **shell)
// {
// 	char	*temp_line;
// 	char	*flag;
// 	char	*test;

// 	test = "-n";
// 	if ((*shell)->pipelist->commands->next == NULL)
// 	{
// 		flag = ft_strdup("");
// 		return (NULL);
// 	}
// 	temp_line = (*shell)->pipelist->commands->next->arg;
// 	if ((*shell)->line == NULL)
// 		return (NULL);
// 	if (temp_line[0] == test[0] && temp_line[1] == test[1])
// 	{
// 		flag = ft_strdup("-n");
// 		if (temp_line[0] == test[0] && temp_line[1] == test[1])
// 			(*shell)->line = "";
// 		else
// 			(*shell)->line = temp_line;
// 	}
// 	else
// 		flag = ft_strdup("");
// 	return (flag);
// }

// void	c_echo(t_shell **shell)
// {
// 	char	*flag;

// 	if ((*shell)->line == NULL)
// 		return ;
// 	flag = flag_echo(shell);
// 	print_args_echo((*shell)->pipelist->commands);
// 	if (flag == NULL || (*shell)->pipelist->commands->next == NULL
// 		|| strcmp_mod(flag, "-n"))
// 		printf("\n");
// 	(*shell)->exit_code = 0;
// 	free (flag);
// }
