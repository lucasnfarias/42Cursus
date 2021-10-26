/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:17 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:47:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < maxlen)
		return (len);
	return (maxlen);
}
