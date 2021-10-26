/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:32:40 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/26 19:26:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "libft.h"

# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>

size_t		ft_strlen(char const *s);
size_t		ft_strnlen(char const *s, size_t maxlen);
size_t		ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t		ft_strlcat(char *dst, char const *src, size_t dstsize);
char		*ft_strchr(char const *s, int c);
char		*ft_strrchr(char const *s, int c);
char		*ft_strnstr(char const *big, char const *little, size_t len);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
int			ft_strcmp(char const *s1, char const *s2);
long long	ft_atoill(char const *str);
int			ft_atoi(char const *str);
double		ft_atof(char *input);
char		*ft_strdup(char const *s1);
char		*ft_strndup(char const *s, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
int			ft_algs_num(long long n);
int			ft_algs_num_base(long long number, unsigned int radix);
char		*ft_repeatchr(unsigned char c, int times);
char		*ft_itoa(int n);
char		*ft_ftoa(long double number, int precision);
char		*ft_llitoa(long long n);
char		*ft_ullitoa(unsigned long long n);
char		*ft_itoabase(int number, char const *base);
char		*ft_llitoabase(long long number, char const *base);
char		*ft_ullitoabase(unsigned long long number, char const *base);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtoupper(char *str);
int			ft_hexfloat_signal(double number);
int			ft_hexfloat_precision(double number);
int			ft_hexfloat_exp(double number);
char		*ft_hexfloat_mantissa(double number, int precision);
int			ft_stdfloat_precision(long double value, int precision);
int			ft_stdfloat_exp(double number);
char		*ft_stdfloat_num(long double number, int precision);
char		*ft_nitoa(char size, int value);
char		*ft_stdfloat_limits(long double number);
char		*ft_strreplace_all(char old, char neww, char *src);
int			ft_count_segment(char const *str, char c);
char		*ft_strreplace(char *str, char *old, char *new);
char		*ft_strreplace_all2(char *str, char *old, char *new);
long		ft_strtol(char *nptr, char **endptr, int base);
char		*ft_strstr(char const *haystack, const char *needle);

#endif
