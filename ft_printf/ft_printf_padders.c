/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:51:12 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 21:19:05 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chr_repeat(char c, size_t times)
{
	char *str;

	if (!(str = malloc((times + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}

static void	ft_check_neg_before(int neg, t_ft_printf_group *group)
{
	if (neg == -1 && group->flags->padding_char == '0')
		ft_printf_putchar(group->params, '-');
}

static void	ft_check_neg_after(int neg, t_ft_printf_group *group)
{
	if (neg == -1 && group->flags->padding_char == ' ' &&
			!group->flags->side)
		ft_printf_putchar(group->params, '-');
}

void		ft_printf_width_handler(int required, t_ft_printf_group *group)
{
	char	*padding;
	size_t	i;

	i = 0;
	if (!group->flags->width_enabled || required < 0)
		return ;
	padding = ft_chr_repeat(group->flags->padding_char, required);
	if (!padding)
		return ;
	while (padding[i])
	{
		ft_putchar_fd(padding[i], group->params->fd);
		i++;
		group->params->return_value += 1;
	}
	free(padding);
}

void		ft_printf_width_handler_num(int required, t_ft_printf_group *group,
			int neg)
{
	char	*padding;
	size_t	i;

	i = 0;
	if (group->flags->precision_enabled && !group->flags->precision_negative)
		group->flags->padding_char = ' ';
	if (!group->flags->width_enabled || required <= 0)
		return ;
	padding = ft_chr_repeat(group->flags->padding_char, required);
	ft_check_neg_before(neg, group);
	if (!padding)
		return ;
	while (padding[i])
	{
		ft_putchar_fd(padding[i], group->params->fd);
		i++;
		group->params->return_value += 1;
	}
	ft_check_neg_after(neg, group);
	free(padding);
}
