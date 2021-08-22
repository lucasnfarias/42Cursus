/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:14:43 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/22 19:15:41 by lniehues         ###   ########.fr       */
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

typedef struct s_int_node
{
	struct s_int_node	*previous;
	int					number;
	struct s_int_node	*next;
}						t_int_node;

typedef struct s_stacks
{
	t_int_node	*a;
	t_int_node	*b;
}				t_stacks;

/*
**	MAIN FUNCTIONS:
*/

void		display_stack(t_int_node *head, char *stack_name);
void		push_stack(t_int_node **head, int new_number);
void		reverse_push_stack(t_int_node **head, int new_number);
t_int_node	*pop_stack(t_int_node **head);
t_int_node	*reverse_pop_stack(t_int_node **head);

/**
 * OPERATIONS FUNCTIONS:
 * 
 * 	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if
 * 	there is only one or no elements).
 *	
 *	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if
 *	there is only one or no elements).
 *	
 *	ss : sa and sb at the same time.
 *	
 *	pa : push a - take the first element at the top of b and put it at the top of a.
 *	Do nothing if b is empty.
 *	
 *	pb : push b - take the first element at the top of a and put it at the top of b.
 *	Do nothing if a is empty.
 *	
 *	ra : rotate a - shift up all elements of stack a by 1. The first element becomes
 *	the last one.
 *	
 *	rb : rotate b - shift up all elements of stack b by 1. The first element becomes
 *	the last one.
 *	
 *	rr : ra and rb at the same time.
 *	
 *	rra : reverse rotate a - shift down all elements of stack a by 1. The last
 *	element becomes the first one.
 *
 */

void		ps_swap(t_int_node **head);
void		ps_push(t_int_node **stack_from, t_int_node **stack_to);
void		ps_rotate(t_int_node **head);
void		ps_reverse_rotate(t_int_node **head);

#endif
