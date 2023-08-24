/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 05:33:59 by tasantos          #+#    #+#             */
/*   Updated: 2023/08/20 05:08:23 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	number_pipes(t_shell **shell)
{
	if ((*shell)->current->commands_n > 1 && (*shell)->pipelist_n > 1)
	{
		(*shell)->exit_code = 1;
		return (TRUE);
	}
	return (FALSE);
}

void	export_var(t_shell **shell, char *key, char *value)
{
	t_env	*var;
	int		value_len;

	var = find_var(shell, key, ft_strlen(key), 0);
	if (!var)
		export_new_var(shell, key, value);
	else if (var)
	{
		if (value)
		{
			value_len = ft_strlen(value);
			if (value_len == 1 && value[0] == '=')
				value[0] = 1;
			else if (value[0] == '=')
				value += 1;
			safe_free(&var->value);
			var->value = ft_substr(value, 0, value_len + 1);
		}
	}
}
