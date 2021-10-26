/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:35:16 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 18:57:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1028
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

size_t	ft_strlen_(char const *s);
char	*ft_strdup_(const char *s1);
size_t	ft_strlcpy_(char *dst, char const *src, size_t dstsize);
char	*ft_strjoin_(char const *s1, char const *s2);
char	*ft_substr_(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
