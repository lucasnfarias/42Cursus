/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:36:21 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:40:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <inttypes.h>

/*
** LST
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** MEM
*/

void			*ft_memset(void *b, int c, size_t len);

void			*ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memccpy(void *dst, const void *src,
					int c, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** STR
*/

size_t			ft_strlen(const char *s);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** ATO?
*/

int				ft_atoi(const char *str);

long long int	ft_atoll(const char *str);

/*
** IS_SOMETHING
*/

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

/*
** TO
*/

int				ft_toupper(int c);

int				ft_tolower(int c);

/*
** WEIRDOS (sorry, i'm lazy sometimes)
*/

char			*ft_strdup(const char *s1);

void			*ft_calloc(size_t count, size_t size);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** PUT
*/

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

/*
** GNL
*/

typedef struct s_gnl_stats
{
	int				init;
	int				reached;
	unsigned char	buffer[201];
	size_t			byte_read;
	size_t			offset;
	unsigned char	*stored;
	size_t			pos;
}					t_gnl_stats;

int				get_next_line(int fd, char **line);

int				get_next_line(int fd, char **line);

#endif
