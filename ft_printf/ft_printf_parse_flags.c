/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:54:39 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 15:12:05 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_parse_value(t_ft_printf_group *group, char *str)
{
	int	value;

	if (str[*(group->i)] == '*')
	{
		value = va_arg(group->params->arguments, int);
		*(group->i) += 1;
	}
	else
	{
		value = ft_atoi(str + *(group->i));
		*(group->i) += ft_itoa_base_length(value, 10) - 1;
	}
	return (value);
}

static void	ft_pf_parse_width(t_ft_printf_group *group, char *str)
{
	int	value;

	group->flags->width_enabled = 1;
	value = ft_pf_parse_value(group, str);
	if (value < 0)
	{
		group->flags->side = 1;
		value *= -1;
		group->flags->width_negative = 1;
		group->flags->padding_char = ' ';
	}
	group->flags->width_value = value;
}

static void	ft_pf_parse_precision(t_ft_printf_group *group, char *str)
{
	int		value;
	size_t	skipped_zeros;

	*(group->i) += 1;
	skipped_zeros = 0;
	while ((str[*(group->i) + skipped_zeros]) == '0')
	{
		skipped_zeros++;
	}
	group->flags->precision_enabled = 1;
	value = ft_pf_parse_value(group, str);
	if (value < 0)
	{
		value *= -1;
		group->flags->precision_negative = 1;
	}
	group->flags->precision_value = value;
	*(group->i) += skipped_zeros;
	if (value == 0)
		*(group->i) -= 1;
}

static void	ft_printf_parse_handler(t_ft_printf_group *group, char *str)
{
	char	c;

	c = str[*(group->i)];
	if (c == '-')
	{
		group->flags->minus_sign = 1;
		group->flags->padding_char = ' ';
		group->flags->side = 1;
	}
	else if (c == '0')
	{
		if (!group->flags->minus_sign)
			group->flags->padding_char = '0';
	}
	else
	{
		if ((c = str[*(group->i)]) != '.')
			ft_pf_parse_width(group, str);
		if ((c = str[*(group->i)]) == '.')
			ft_pf_parse_precision(group, str);
	}
}

void		ft_printf_parse_flags(t_ft_printf_group *group, size_t start,
			size_t end)
{
	size_t	length;
	char	*str_flag;
	size_t	index;
	size_t	*old_index;

	length = end - start;
	if (!(str_flag = malloc((length + 1) * sizeof(char))))
		return ;
	ft_memcpy(str_flag, group->params->format + start, length);
	str_flag[length] = '\0';
	index = 0;
	old_index = group->i;
	group->i = &index;
	while (index < length)
	{
		ft_printf_parse_handler(group, str_flag);
		index++;
	}
	group->i = old_index;
	free(str_flag);
}
