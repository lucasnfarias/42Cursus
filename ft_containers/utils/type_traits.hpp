/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:37:04 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/05 19:40:16 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {

// enable_if (prevent compilation if condition is not met)
template <bool Cond, class T = void> struct enable_if {};

// Partial specialization
template<class T> struct enable_if<true, T> { typedef T type; };

// This template is designed to provide compile-time constants as types.
template<class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;
  operator value_type() { return value; }
};

// booleans that we can inherit
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// general implementation (false for T that are not considered as integral)
template<class T> struct is_integral : false_type {};
template <class T> struct is_integral<const T> : is_integral<T> {};
template <class T> struct is_integral<volatile T> : is_integral<T> {};
template <class T> struct is_integral<const volatile T> : is_integral<T> {};

// specializations (this are the types that are integral)
template <> struct is_integral<bool> : true_type {};
template <> struct is_integral<char> : true_type {};
// template <> struct is_integral<char16_t> : true_type {};
// template <> struct is_integral<char32_t> : true_type {};
template <> struct is_integral<wchar_t> : true_type {};
template <> struct is_integral<signed char> : true_type {};
template <> struct is_integral<short int> : true_type {};
template <> struct is_integral<int> : true_type {};
template <> struct is_integral<long int> : true_type {};
template <> struct is_integral<long long int> : true_type {};
template <> struct is_integral<unsigned char> : true_type {};
template <> struct is_integral<unsigned short int> : true_type {};
template <> struct is_integral<unsigned int> : true_type {};
template <> struct is_integral<unsigned long int> : true_type {};
template <> struct is_integral<unsigned long long int> : true_type {};

}

#endif
