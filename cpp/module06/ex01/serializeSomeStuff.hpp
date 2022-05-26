/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializeSomeStuff.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:00:59 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:17:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZESOMESTUFF_HPP
# define SERIALIZESOMESTUFF_HPP

# include <iostream>
# include <stdint.h>

typedef struct  s_Data
{
  std::string s1;
  int i;
}               Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
