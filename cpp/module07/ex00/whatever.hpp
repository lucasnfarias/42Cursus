/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:12:17 by coder             #+#    #+#             */
/*   Updated: 2022/05/30 23:55:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	const &min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template<typename T>
T	const &max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif