/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:34:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 16:23:10 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_directory(const char *path)
{
	struct stat	sb;

	if (!path)
		return (false);
	if (stat(path, &sb) != 0)
		return (false);
	return (S_ISDIR(sb.st_mode));
}

bool	is_executable(const char *path)
{
	struct stat	sb;

	if (!path)
		return (false);
	if (stat(path, &sb) != 0)
		return (false);
	return (S_ISDIR(sb.st_mode));
}
