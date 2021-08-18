/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:14:43 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/17 21:42:06 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "liberror.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>

/*
** COLOR MACROS:
*/

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
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define RESET_COLOR "\033[0m"

/*
** STRUCTS:
*/

typedef struct s_int_list
{
	int					number;
	struct s_int_list	*next;
	struct s_int_list	*previous;
}						t_int_list;

typedef struct s_stack
{
	t_int_list	*a;
	t_int_list	*b;
}				t_stack;

#endif
