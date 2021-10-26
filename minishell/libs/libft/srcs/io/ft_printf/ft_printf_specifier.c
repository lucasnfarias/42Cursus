/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:45:53 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/29 09:16:44 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_specifier_diuoxp(t_print_op *op)
{
	void	(*f[127])();

	f['d' - 0] = ft_spec_di;
	f['i' - 0] = ft_spec_di;
	f['u' - 0] = ft_spec_u;
	f['o' - 0] = ft_spec_o;
	f['x' - 0] = ft_spec_x;
	f['X' - 0] = ft_spec_x;
	f['p' - 0] = ft_spec_p;
	f[op->specifier - 0]();
}

void	ft_printf_specifier_fega(t_print_op *op)
{
	void	(*f[127])();

	f['f' - 0] = ft_spec_f;
	f['F' - 0] = ft_spec_f;
	f['e' - 0] = ft_spec_e;
	f['E' - 0] = ft_spec_e;
	f['g' - 0] = ft_spec_g;
	f['G' - 0] = ft_spec_g;
	f['a' - 0] = ft_spec_a;
	f['A' - 0] = ft_spec_a;
	f[op->specifier - 0]();
}

void	ft_printf_specifier_csper(t_print_op *op)
{
	void	(*f[127])();

	f['c' - 0] = ft_spec_c;
	f['s' - 0] = ft_spec_s;
	f['%' - 0] = ft_spec_per;
	f[op->specifier - 0]();
}

void	ft_printf_specifier(t_print_op *op)
{
	if (op->specifier == 'n')
		ft_spec_n(op);
	else if (ft_strchr("cs%%", op->specifier))
		ft_printf_specifier_csper(op);
	else if (ft_strchr("diuoxXp", op->specifier))
		ft_printf_specifier_diuoxp(op);
	else if (ft_strchr("fFeEgGaA", op->specifier))
		ft_printf_specifier_fega(op);
	else
		op->v_value = ft_repeatchr(op->specifier, 1);
}
