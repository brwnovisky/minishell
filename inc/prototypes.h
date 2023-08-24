/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:54 by bluiz-al          #+#    #+#             */
/*   Updated: 2023/08/20 20:11:57 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*----------------------------------------------------------------------------*/
/*                           builtins.c                                       */
/*----------------------------------------------------------------------------*/
void	*is_built_in(char *command);

/*----------------------------------------------------------------------------*/
/*                           cd.c                                             */
/*----------------------------------------------------------------------------*/
void	c_cd(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           cd.c                                             */
/*----------------------------------------------------------------------------*/
int		change_directory(char *new_path);

/*----------------------------------------------------------------------------*/
/*                           echo.c                                           */
/*----------------------------------------------------------------------------*/
void	c_echo(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           env.c                                            */
/*----------------------------------------------------------------------------*/
void	c_env(t_shell **shell);
void	make_env(t_shell **shell, char **envp, int str_len);
void	print_env(t_shell **shell, int is_export);
t_env	*find_var(t_shell **shell, char *key, int key_len, int is_unset);

/*----------------------------------------------------------------------------*/
/*                           execution.c                                      */
/*----------------------------------------------------------------------------*/
void	execution(t_shell **shell, t_block **current);

/*----------------------------------------------------------------------------*/
/*                           execve_matrixes.c                                */
/*----------------------------------------------------------------------------*/
void	execve_matrixes(t_shell **shell, t_block *current);
void	free_execve_env_matrix(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           exit.c                                           */
/*----------------------------------------------------------------------------*/
void	c_exit(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           export.c                                         */
/*----------------------------------------------------------------------------*/
void	c_export(t_shell **shell);
void	export_new_var(t_shell **shell, char *key, char *value);
void	export_var(t_shell **shell, char *key, char *value);

/*----------------------------------------------------------------------------*/
/*                           export2.c                                        */
/*----------------------------------------------------------------------------*/
int		number_pipes(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           heredoc.c                                        */
/*----------------------------------------------------------------------------*/
char	*here_doc_setup(t_shell **shell, t_block *current, char *line);
void	here_doc_exec(t_shell **shell, t_block *current, char *delimiter);
void	heredoc_name_setup(t_shell **shell, t_block *current);

/*----------------------------------------------------------------------------*/
/*                           minishell.c                                      */
/*----------------------------------------------------------------------------*/
void	minishell(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           perror_free_exit.c                               */
/*----------------------------------------------------------------------------*/
void	free_pipe_list(t_shell **shell, t_block *current);
void	free_shell(t_shell **shell);
void	safe_free(void *pointer);
void	free_args_matrix(t_block *current, char **args);

/*----------------------------------------------------------------------------*/
/*                           pipe_list.c                                      */
/*----------------------------------------------------------------------------*/
char	*special_cases(t_shell **shell, t_block *current, char *line);
void	pipe_list_build(t_shell **shell, char *line);
void	manage_file_descriptors(t_block *current, char *file_name);
void	new_command(t_block *current);
t_block	*new_block_on_pipe_list(t_shell **shell, t_block *block_current);

/*----------------------------------------------------------------------------*/
/*                           pwd_list.c                                       */
/*----------------------------------------------------------------------------*/
void	c_pwd(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           quotes.c                                         */
/*----------------------------------------------------------------------------*/
char	*is_quote(t_block *current, char *line);
char	*quotes_clean(t_block *current, char **arg, char *a_free, int arg_len);

/*----------------------------------------------------------------------------*/
/*                           signals.c                                        */
/*----------------------------------------------------------------------------*/
void	handle_sigint(int signal);
void	handle_sigquit(t_shell **shell);
void	signal_handled_exec(t_shell **shell);
void	signal_listener(__sighandler_t handle_quit, __sighandler_t handle_int);

/*----------------------------------------------------------------------------*/
/*                           split_commands.c                                 */
/*----------------------------------------------------------------------------*/
char	**split_commands(t_shell **shell, char *s, char c);

/*----------------------------------------------------------------------------*/
/*                           unset.c                                          */
/*----------------------------------------------------------------------------*/
void	c_unset(t_shell **shell);

/*----------------------------------------------------------------------------*/
/*                           utils.c                                          */
/*----------------------------------------------------------------------------*/
char	*strchr_mod(const char *str, int c);
int		ft_atoi64(const char *nptr);
int		strcmp_mod(const char *s1, const char *s2);

/*----------------------------------------------------------------------------*/
/*                           validations_input.c                              */
/*----------------------------------------------------------------------------*/
char	*is_command(t_shell **shell, t_block *current, char *line);
char	*is_file_io(t_shell **shell, t_block *current, char *line);
char	*is_spaces(char *line, char *spaces);
char	*is_special(t_shell **shell, t_block *current, char *line, char *spcls);
int		var_define(t_shell **shell, t_block *current, int arg_len);

/*----------------------------------------------------------------------------*/
/*                           validations_input2.c                             */
/*----------------------------------------------------------------------------*/
char	*is_no_word(t_shell **shell, t_block *current, char *line);
int		is_parent_builtins(void *builtin, int commands_n);
int		command_validate(t_shell **shell, t_block *current);

/*----------------------------------------------------------------------------*/
/*                           validations_input3.c                             */
/*----------------------------------------------------------------------------*/
void	is_var(t_shell **shell, t_block *current, char *arg, int arg_len);

#endif