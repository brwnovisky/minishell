/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:44 by bluiz-al          #+#    #+#             */
/*   Updated: 2023/08/19 17:23:51 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   MINISHELL_H
# define  MINISHELL_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../lib/libft/libft.h"
# include "constants.h"
# include "enums.h"
# include "structs.h"
# include "prototypes.h"

extern int	g_signal;

#endif