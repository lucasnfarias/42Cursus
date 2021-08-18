/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:29:56 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/17 21:33:07 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_msg_error(char *error_code)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(error_code, 2);
	exit(errno);
}
