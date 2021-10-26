/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:11:30 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 17:16:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strreplace_all(char old, char new, char *src)
{
	char	*temp;

	if (!src)
		return (NULL);
	temp = src;
	while (*src)
		if (*(src++) == old)
			*(src - 1) = new;
	return (temp);
}
