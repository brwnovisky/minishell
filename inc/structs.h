/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluiz-al <bluiz-al@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:12 by bluiz-al          #+#    #+#             */
/*   Updated: 2023/08/20 05:31:47 by bluiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*arg;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_quote
{
	char			quote;
	struct s_quote	*next;
}					t_quote;

typedef struct s_block
{
	char			**args;
	char			*expand;
	char			*arg_0;
	char			*cmd;
	char			*file_name;			
	char			*heredoc_name;			
	char			quote_tmp;			
	enum e_set		set;
	int				commands_n;			
	int				fd[2];
	int				pipe[2];
	int				signal;
	int				quotes_n;			
	pid_t			pid;
	struct s_block	*next;
	t_cmd			*commands;
	t_cmd			*current_command;
	t_quote			*current_quote;
	t_quote			*quotes_list;
	void			(*built_in)(void *shell);
}					t_block;

typedef struct s_shell
{
	char			**env_mtx;
	char			**paths_mtx;
	char			*heredoc_name;
	int				count;
	int				env_n;
	int				paths_n;
	int				pipelist_n;
	t_block			*current;
	t_block			*pipelist;
	t_block			*previous;
	t_env			*env;
	t_env			*env_last;
	u_int8_t		exit_code;
}					t_shell;

#endif