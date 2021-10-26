/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:52:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/15 23:41:44 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "io.h"
# include "ft_printf_util.h"
# include "specifiers/specifiers.h"

# include <stdarg.h>
# include <stdbool.h>

int		parse_specifier(t_print_op *operation);
int		parse_length(t_print_op *operation);
int		parse_precision(t_print_op *operation);
int		parse_width(t_print_op *operation);
int		parse_flags(t_print_op *operation);
int		ft_printf_parser(t_print_op *operation);
void	ft_printf_specifier(t_print_op *op);
void	ft_printf_width(t_print_op *op);
void	ft_printf_precision(t_print_op *op);
void	ft_printf_flags(t_print_op *op);
int		ft_vprintf(const char *format, va_list *arguments);
int		ft_printf(const char *format, ...);

#endif
