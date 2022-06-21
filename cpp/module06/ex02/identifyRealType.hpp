/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyRealType.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:25:13 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:38:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFYREALTYPE_HPP
# define IDENTIFYREALTYPE_HPP

class Base {

public:
  virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
