/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder_appender.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:46:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/18 21:53:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_builder.h"

static t_str_builder	*str_builder_ensure_space(
	t_str_builder *builder,
	size_t required)
{
	char	*temp;

	if (!builder)
		return (NULL);
	if (required <= builder->available)
		return (builder);
	temp = ft_calloc(1, builder->used + builder->available
			+ required + STR_BUILDER_LEN + 1);
	if (!temp)
		return (NULL);
	ft_memmove(temp, builder->str, builder->used);
	free(builder->str);
	builder->str = temp;
	builder->available = builder->available + required + STR_BUILDER_LEN;
	return (builder);
}

t_str_builder	*str_builder_add_char(t_str_builder *builder, char c)
{
	if (!builder)
		return (NULL);
	if (!str_builder_ensure_space(builder, 1))
		return (NULL);
	ft_memmove(builder->str + builder->used, &c, 1);
	builder->used++;
	builder->available--;
	return (builder);
}

t_str_builder	*str_builder_add_str_len(
	t_str_builder *builder,
	char *str,
	size_t len)
{
	if (!builder || !str)
		return (NULL);
	if (!str_builder_ensure_space(builder, len))
		return (NULL);
	ft_memmove(builder->str + builder->used, str, len);
	builder->used += len;
	builder->available -= len;
	return (builder);
}

t_str_builder	*str_builder_add_str(t_str_builder *builder, char *str)
{
	if (!builder || !str)
		return (NULL);
	return (str_builder_add_str_len(builder, str, ft_strlen(str)));
}
