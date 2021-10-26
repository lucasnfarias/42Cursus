/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:11:30 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/18 21:57:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strreplace(char *str, char *old, char *new)
{
	int		index;
	char	*result;
	size_t	old_size;
	size_t	new_size;
	size_t	str_size;

	index = -1;
	old_size = ft_strlen(old);
	new_size = ft_strlen(new);
	str_size = ft_strlen(str);
	while (str[++index])
	{
		if (ft_strncmp(old, str + index, old_size) != 0)
			continue ;
		result = malloc(str_size + new_size + 1 - old_size);
		if (!result)
			return (NULL);
		ft_memmove(result, str, index);
		ft_memmove(result + index, new, new_size);
		ft_memmove(result + index + new_size, str + index + old_size,
			str_size - index - old_size);
		return (result);
	}
	return (ft_strdup(str));
}

char	*ft_strreplace_all2(char *str, char *old, char *new)
{
	size_t	len;
	char	*temp;
	char	*temp2;

	len = ft_strlen(str);
	temp = ft_strdup(str);
	while (ft_strnstr(temp, old, len))
	{
		temp2 = ft_strreplace(temp, old, new);
		free(temp);
		temp = temp2;
	}
	return (temp);
}
