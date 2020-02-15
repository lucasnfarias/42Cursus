/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_handle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:18:26 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/11 17:28:40 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strchr_printf(const char *s, int c)
{
	char	let;
	size_t	i;

	i = 0;
	let = (char)c;
	while (*s != '\0')
	{
		if (*s == let)
			return (1);
		else
			++s;
	}
	if (let == '\0')
		return (0);
	return (0);
}

static void		ft_printf_select_formats(t_ft_printf_group *group)
{
	unsigned char		c;

	c = group->flags->letter_format;
	if (c == '%')
		ft_printf_format_percentage(group);
	else if (c == 'c')
		ft_printf_format_char(group);
	else if (c == 's')
		ft_printf_format_str(group);
	else if (c == 'd' || c == 'i')
		ft_printf_format_decimal(group);
	else if (c == 'p')
		ft_printf_format_pointer(group);
	else if (c == 'x' || c == 'X')
		ft_printf_format_int_hex(group);
	else if (c == 'u')
		ft_printf_format_uint(group);
}

void			ft_printf_format_handle(t_ft_printf_params *params, size_t *i)
{
	t_ft_printf_flags	flags;
	t_ft_printf_group	group;
	size_t				start;

	group = (t_ft_printf_group) {params, &flags, i};
	ft_printf_flags_init(&flags);
	start = *i;
	flags.letter_format = params->format[*i];
	while (!(ft_strchr_printf("cspdiuxX%", flags.letter_format)))
	{
		*i += 1;
		flags.letter_format = params->format[*i];
	}
	if (start != *i)
	{
		ft_printf_parse_flags(&group, start, *i);
		ft_printf_select_formats(&group);
		*i += 1;
	}
	else
	{
		ft_printf_select_formats(&group);
		*i += 1;
	}
}
