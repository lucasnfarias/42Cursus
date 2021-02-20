/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:58:14 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/11 17:09:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_empty_str(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}