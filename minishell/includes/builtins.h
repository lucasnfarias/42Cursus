/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:25:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/13 14:13:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

# define ERR_NOT_FOUND "command not found"
# define ERR_IS_DIR "Is a directory"
# define TOO_MANY_ARGS "too many arguments"
# define NUM_ARG_REQUIRED "numeric argument required"

void	exit_builtin(char **argv);
void	cd_builtin(char **argv);
void	echo_builtin(char **argv);
void	env_builtin(void);
void	export_builtin(char	**args);
void	pwd_builtin(void);
void	unset_builtin(char **args);

#endif
