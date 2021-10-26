/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:45:59 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/18 21:54:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_builder.h"

t_str_builder	*str_builder_init(void)
{
	t_str_builder	*str_builder;

	str_builder = malloc(sizeof(t_str_builder));
	if (!str_builder)
		return (NULL);
	str_builder->str = ft_calloc(1, STR_BUILDER_LEN + 1);
	if (!str_builder->str)
		return (NULL);
	str_builder->used = 0;
	str_builder->available = STR_BUILDER_LEN;
	return (str_builder);
}

void	str_builder_destroy(t_str_builder *builder)
{
	if (!builder)
		return ;
	if (builder->str)
		free(builder->str);
	free(builder);
}
