/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:52:18 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/18 21:59:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_BUILDER_H
# define STR_BUILDER_H

# include "libft.h"

# define STR_BUILDER_LEN 100

typedef struct s_str_builder
{
	char	*str;
	size_t	used;
	size_t	available;
}			t_str_builder;

t_str_builder	*str_builder_init(void);
void			str_builder_destroy(
					t_str_builder *builder);
t_str_builder	*str_builder_add_char(
					t_str_builder *builder,
					char c);
t_str_builder	*str_builder_add_str_len(
					t_str_builder *builder,
					char *str,
					size_t len);
t_str_builder	*str_builder_add_str(
					t_str_builder *builder,
					char *str);

#endif
