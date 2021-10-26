/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:50:00 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/29 21:09:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
# define SPECIFIERS_H

# include "../ft_printf.h"

void	ft_spec_a(t_print_op *op);
void	ft_spec_c(t_print_op *op);
void	ft_spec_di(t_print_op *op);
void	ft_spec_e(t_print_op *op);
void	ft_spec_f(t_print_op *op);
void	ft_spec_g(t_print_op *op);
void	ft_spec_n(t_print_op *op);
void	ft_spec_o(t_print_op *op);
void	ft_spec_p(t_print_op *op);
void	ft_spec_per(t_print_op *op);
void	ft_spec_s(t_print_op *op);
void	ft_spec_u(t_print_op *op);
void	ft_spec_x(t_print_op *op);
void	ft_spec_e_helper(t_print_op *op);

#endif
