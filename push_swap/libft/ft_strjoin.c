/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:15:12 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/27 20:48:17 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new == NULL)
		return (NULL);
	while (*s1)
		*(new++) = *(s1++);
	while (*s2)
		*(new++) = *(s2++);
	*new = '\0';
	return (new - (len_s1 + len_s2));
}
