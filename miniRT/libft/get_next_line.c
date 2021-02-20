/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:02:30 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/19 18:25:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This is a modified version of the original get_next_line project running with
** a fixed buffer size for ease of use.
*/

static int		ft_line_add(char **str, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr_gnl(*str, 0, i);
		temp = ft_strdup_gnl(&((*str)[i + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup_gnl(*str);
		ft_strdel(str);
		return (0);
	}
	return (1);
}

static int		ft_return(char **str, char **line, int n, int fd)
{
	if (n < 0)
		return (-1);
	else if (n == 0 && str[fd] == NULL)
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (ft_line_add(&str[fd], line));
}

int				get_next_line(int fd, char **line)
{
	static char	*str[200];
	char		*buffer;
	char		*temp;
	int			n;

	if (!(buffer = (char *)malloc(sizeof(char) * (200 + 1))))
		return (0);
	if (fd < 0 || line == 0 || 200 < 1)
		return (-1);
	while ((n = read(fd, buffer, 200)) > 0)
	{
		buffer[n] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup_gnl(buffer);
		else
		{
			temp = ft_strjoin_gnl(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	ft_strdel(&buffer);
	return (ft_return(str, line, n, fd));
}
