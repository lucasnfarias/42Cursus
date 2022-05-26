/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializeSomeStuff.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:03:43 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:08:32 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializeSomeStuff.hpp"

uintptr_t serialize(Data* ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}
