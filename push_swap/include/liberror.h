/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberror.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:16:43 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/18 21:17:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERROR_H
# define LIBERROR_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>

/*
** ERROR MESSAGE MACROS:
*/

# define NO_INPUT "No input found! Please, insert some integers as arguments."

# define NOT_DIGIT "Sorry, mate! I only accept integers."

# define INPUT_TOO_HIGH "Ops... integer higher than the int limit."

# define INPUT_TOO_LOW "Ops... integer lower than the int limit."

# define DUPLICATE_INPUT "There are some impostors. Check for duplicates!"

/*
** ERROR HANDLING FUNCTIONS:
*/

void	exit_with_msg_error(char *error_code);
void	validate_input(char **argv);

#endif
