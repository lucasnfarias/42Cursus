/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:54:51 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/31 20:55:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_three_int(int *first, int *second, int *third, t_stacks *stacks)
{
	*first = stacks->a->number;
	*second = stacks->a->next->number;
	*third = stacks->a->previous->number;
}

void	sort_three_numbers(t_stacks *stacks)
{
	int	fst;
	int	snd;
	int	trd;

	set_three_int(&fst, &snd, &trd, stacks);
	if (fst < snd && snd > trd && trd > fst)
	{
		ps_reverse_rotate(&stacks->a, "rra\n");
		ps_swap(&stacks->a, "sa\n");
	}
	else if (fst > snd && snd < trd && trd > fst)
		ps_swap(&stacks->a, "sa\n");
	else if (fst < snd && snd > trd && trd < fst)
		ps_reverse_rotate(&stacks->a, "rra\n");
	else if (fst > snd && snd > trd && trd < fst)
	{
		ps_rotate(&stacks->a, "ra\n");
		ps_swap(&stacks->a, "sa\n");
	}
	else if (fst > snd && snd < trd && trd < fst)
		ps_rotate(&stacks->a, "ra\n");
}
