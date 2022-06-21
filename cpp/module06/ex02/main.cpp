/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:29:41 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:49:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifyRealType.hpp"

int main()
{
  Base *randomClass = generate();
  Base &class_reference = *randomClass;
  identify(randomClass);
  identify(class_reference);
  delete randomClass;
}
