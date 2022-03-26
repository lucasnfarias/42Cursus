/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:45:19 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 21:59:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class Harl {

private:
  void _debug( void );
  void _info( void );
  void _warning( void );
  void _error( void );
  void _messageBuilder(std::string level, std::string message);
  std::string _level;

public:
  Harl(const std::string level);
  ~Harl(void);
  void complain( void );
};

typedef void (Harl::*methodPtr)(void);

#endif
