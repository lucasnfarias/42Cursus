/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:45:19 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 22:59:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class Harl {

public:
  enum filterLevel {
    errorLevel = 0,
    warningLevel,
    infoLevel,
    debugLevel,
    defaultLevel = -1
  };
  
  Harl(const std::string level);
  ~Harl(void);
  
  filterLevel getLevelFromString(std::string level);
  filterLevel getLevel(void) const;
  void complain(std::string level);

private:
  void _debug( void );
  void _info( void );
  void _warning( void );
  void _error( void );
  void _messageBuilder(std::string level, std::string message);
  filterLevel _level;
};

typedef void (Harl::*methodPtr)(void);

#endif
