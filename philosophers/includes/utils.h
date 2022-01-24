/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:25:21 by lniehues          #+#    #+#             */
/*   Updated: 2021/12/05 13:17:43 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philosophers.h"
/*
** Color definitions, because colors make everything more fun :)
*/

# define BLACK "\033[0;30m"
# define BOLD_BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define ITALIC_GREEN "\033[3;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define ITALIC_YELLOW "\033[3;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define ITALIC_BLUE "\033[3;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define UNDERLINED_PURPLE "\033[4;35m"
# define CYAN "\033[0;36m"
# define ITALIC_CYAN "\033[3;36m"
# define BOLD_CYAN "\033[1;36m"
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define RESET_COLOR "\033[0m"

/* LIBFT */
int				ft_isdigit(int c);
int				ft_isspace(int c);

long long		ft_atoill(char const *str);
int				ft_atoi(char const *str);

char			*ft_itoa(int n);

/* TIME */
long long int	get_current_time(void);
long long int	timestamp(long long int session_start);
void			wait_time_in_ms(long long int miliseconds_time);

#endif
