/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:45:19 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 21:44:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class Harl {

private:
  void debug( void );
  void info( void );
  void warning( void );
  void error( void );

public:
  Harl(void);
  ~Harl(void);
  void complain( std::string level );
};

typedef void (Harl::*methodPtr)(void);

#endif
