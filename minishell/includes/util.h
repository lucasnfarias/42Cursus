/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:14:59 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/19 07:55:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "minishell.h"

char	*ft_strrstr(char const *big, const char *little);
void	free_str_array(char **str_array);
void	exit_minishell(void);
char	**str_list_array(t_dlist *args);
void	copy_buffer(int from_fd, int to_fd);
void	open_std_fd(void);
void	restore_std_fd(void);
void	null_std_fd(void);
void	close_std_fd(void);
int		*pipe_create(void);
void	pipe_free(int **p);
void	pipe_set_writer(int **p);
void	pipe_set_reader(int **p);
void	set_variable(char *keyvalue);
size_t	array_size(void	**arr);
void	error_handler(char *cmd, char *msg, int status);
void	error_simple(char *msg, int status);
void	error_heredoc_eof(char *value, int heredoc_line);
void	syntax_error(t_token *token);
void	ignore_signals(void);
bool	is_directory(const char *path);
void	error_handler_arg(char *cmd, char *arg, char *msg, int status);
char	*resolve_tilde(char *path);
void	cwd_setup(void);
char	*join_path(char *a, char *b);

#endif
