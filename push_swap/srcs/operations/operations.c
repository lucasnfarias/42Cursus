/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:57:01 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/18 21:00:04 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * HERE WE WILL FIND THE FUTURE OPERATIONS:
 * 
 * 	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
 *	is only one or no elements).
 *	
 *	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
 *	is only one or no elements).
 *	
 *	ss : sa and sb at the same time.
 *	
 *	pa : push a - take the first element at the top of b and put it at the top of a. Do
 *	nothing if b is empty.
 *	
 *	pb : push b - take the first element at the top of a and put it at the top of b. Do
 *	nothing if a is empty.
 *	
 *	ra : rotate a - shift up all elements of stack a by 1. The first element becomes
 *	the last one.
 *	
 *	rb : rotate b - shift up all elements of stack b by 1. The first element becomes
 *	the last one.
 *	
 *	rr : ra and rb at the same time.
 *	
 *	rra : reverse rotate a - shift down all elements of stack a by 1. The last element
 *	becomes the first one.
 *
 */