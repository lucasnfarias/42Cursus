/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:48:24 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/17 20:58:19 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon {

private:

  std::string _type;

public:

  Weapon( void );
  Weapon( std::string type );
  ~Weapon( void );

  std::string getType( void ) const;
  void        setType( std::string type );
};
