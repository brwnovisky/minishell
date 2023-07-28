/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:13 by root              #+#    #+#             */
/*   Updated: 2023/07/15 20:21:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// char	verify_flags(t_shell **shell, char *pattern)
// {
// 	int		i;
// 	char	letter;

// 	i = 0;
// 	letter = '\0';
// 	if ((*shell)->flag != NULL && (*shell)->flag[0] == '-')
// 	{
// 		while ((*shell)->flag[++i] && letter == '\0')
// 		{
// 			if (!ft_strchr(pattern, (*shell)->flag[i]))
// 				letter = (*shell)->flag[i];
// 		}
// 	}
// 	return (letter);
// }

// int	is_flag_null(t_shell **shell, char *pattern)
// {
// 	char	letter;

// 	letter = verify_flags(shell, pattern);
// 	if (letter != '\0')
// 	{
// 		if (!strcmp_mod((*shell)->command, "env") 
// 		|| !strcmp_mod((*shell)->command, "clear"))
// 			printf("%s: invalid option -- '%c'\n", (*shell)->command, letter);
// 		else
// 			printf("minishell: %s: -%c: invalid option\n", (*shell)->command, 
// 			letter);
// 		return (0);
// 	}
// 	return (1);
// }
