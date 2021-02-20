/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:25:05 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/27 13:07:11 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') ||
	(c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}