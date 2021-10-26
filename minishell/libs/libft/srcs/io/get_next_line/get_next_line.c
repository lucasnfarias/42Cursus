/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:41:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 20:56:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr_(char const *str, int c)
{
	if (!str)
		return (0);
	while (*str != c && *str != '\0')
		str++;
	return ((char *)str);
}

static int	buffer_load_(int fd, char **buffer)
{
	char	*temp_read;
	char	*temp_buffer;
	int		length;

	if (!*buffer)
		*buffer = ft_strdup_("");
	temp_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp_read == 0)
		return (-1);
	length = read(fd, temp_read, BUFFER_SIZE);
	if (length == -1)
		return (-1);
	temp_read[length] = '\0';
	temp_buffer = ft_strjoin_(*buffer, temp_read);
	if (temp_buffer == 0)
		return (-1);
	free(*buffer);
	free(temp_read);
	*buffer = temp_buffer;
	return (length);
}

static int	buffer_discharge_(char **buffer, char **line)
{
	int		length;
	int		bsize;
	char	*temp;

	if (!*buffer)
	{
		*line = ft_strdup_("");
		return (0);
	}
	bsize = ft_strlen_(*buffer);
	length = ft_strchr_(*buffer, '\n') - *buffer;
	*line = ft_substr_(*buffer, 0, length);
	temp = ft_substr_(*buffer, length + 1, ft_strlen_(*buffer));
	free(*buffer);
	*buffer = temp;
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (bsize - length);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	int			length;

	if (!line || 0 > fd || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	length = 0;
	while (!buffer[fd] || *ft_strchr_(buffer[fd], '\n') != '\n')
	{
		length = buffer_load_(fd, &buffer[fd]);
		if (length == -1)
			return (-1);
		if (length < BUFFER_SIZE)
			break ;
	}
	if (!buffer_discharge_(&buffer[fd], line) && length < BUFFER_SIZE)
		return (0);
	return (1);
}
