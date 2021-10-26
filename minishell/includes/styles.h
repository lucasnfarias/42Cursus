/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:03:50 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/17 16:57:39 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLES_H
# define STYLES_H

# include "minishell.h"

# define BLACK "\033[0;30m"
# define BOLD_BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define RESET_COLOR "\033[0m"

/*
 * Escaped color codes for readline library
 */

# define ESC_BLACK "\001\033[0;30m"
# define ESC_BOLD_BLACK "\001\033[1;30m\002"
# define ESC_RED "\001\033[0;31m\002"
# define ESC_BOLD_RED "\001\033[1;31m\002"
# define ESC_GREEN "\001\033[0;32m\002"
# define ESC_BOLD_GREEN "\001\033[1;32m\002"
# define ESC_YELLOW "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE "\001\033[0;34m\002"
# define ESC_BOLD_BLUE "\001\033[1;34m\002"
# define ESC_PURPLE "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN "\001\033[0;36m\002"
# define ESC_BOLD_CYAN "\001\033[1;36m\002"
# define ESC_WHITE "\001\033[0;37m\002"
# define ESC_BOLD_WHITE "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"

#endif
