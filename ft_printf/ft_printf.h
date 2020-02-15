/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:46:30 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:18:31 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft/libft.h"

typedef struct	s_ft_printf_params
{
	int			return_value;
	const char	*format;
	va_list		arguments;
	int			fd;

}				t_ft_printf_params;

typedef struct	s_ft_printf_flags
{
	char	letter_format;
	int		hex_lower;
	int		side;
	int		minus_sign;
	int		width_value;
	int		width_enabled;
	int		width_negative;
	int		precision_value;
	int		precision_enabled;
	int		precision_negative;
	char	padding_char;
}				t_ft_printf_flags;

typedef struct	s_ft_printf_group
{
	t_ft_printf_params	*params;
	t_ft_printf_flags	*flags;
	size_t				*i;
}				t_ft_printf_group;

int				ft_printf(const char *format, ...);

void			ft_printf_manager(t_ft_printf_params *params);

void			ft_printf_putchar(t_ft_printf_params *params, char c);
void			ft_printf_putstr(t_ft_printf_group *group, char *str);
void			ft_printf_putdecimal(t_ft_printf_group *group, char *str);
void			ft_printf_putpointer(t_ft_printf_group *group, char *str);
void			ft_printf_put_uint(t_ft_printf_group *group, char *str);

void			ft_printf_format_handle(t_ft_printf_params *params, size_t *i);

void			ft_printf_flags_init(t_ft_printf_flags *flags);
void			ft_printf_parse_flags(t_ft_printf_group *group,
				size_t start, size_t end);

void			ft_printf_format_char(t_ft_printf_group *group);
void			ft_printf_format_str(t_ft_printf_group *group);
void			ft_printf_format_decimal(t_ft_printf_group *group);
void			ft_printf_format_percentage(t_ft_printf_group *group);
void			ft_printf_format_pointer(t_ft_printf_group *group);
void			ft_printf_format_int_hex(t_ft_printf_group *group);
void			ft_printf_format_uint(t_ft_printf_group *group);

size_t			ft_itoa_base_length(long number, size_t base);
char			*ft_itoa_base(long num, char *base);
long long int	ft_abs(long long int number);
size_t			ft_itoa_unsigned_base_len(unsigned long number, size_t base);
char			*ft_itoa_unsigned_base(unsigned long num, char *base);

char			*ft_chr_repeat(char c, size_t times);
void			ft_printf_width_handler(int required, t_ft_printf_group *group);
void			ft_printf_width_handler_num(int required,
				t_ft_printf_group *group, int neg);

char			*ft_empty_str(void);

#endif
