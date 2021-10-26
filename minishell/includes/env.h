/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:12:04 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 21:24:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

void		display_env(t_hashmap *env);
char		*find_env(char *key);
char		*find_command_path(char **path, char *command);
t_hashmap	*env_to_hashmap(char *const env[]);
char		**hashmap_env_to_array_env(t_hashmap *bucket, char *path);

#endif
