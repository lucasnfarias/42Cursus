/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:24 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/31 15:06:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_gnl_stats
{
	int				init;
	int				reached;
	unsigned char	buffer[BUFFER_SIZE];
	size_t			byte_read;
	size_t			offset;
	unsigned char	*stored;
	size_t			pos;
}					t_gnl_stats;

int					get_next_line(int fd, char **line);

void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
