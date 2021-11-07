/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:21:18 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/07 19:06:30 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "utils.h"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>

/*
** Standard macros.
*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 9223372036854775807
# define TRUE 1
# define FALSE 0

/*
** Error messages.
*/

# define TOO_FEW_ARGS "ERROR: One or more arguments missing."
# define TOO_MANY_ARGS "ERROR: There are too many arguments."
# define INPUT_TOO_HIGH "ERROR: Input above int limit. Sky is not the limit."
# define INPUT_TOO_LOW "ERROR: Input is below 1. Why would you do that, right?"
# define NOT_DIGIT "ERROR: Input should be an integer. thx :)"
# define TOO_MANY_PHILOS "Too many minds and tummies to feed."
# define ZERO_PHILOS "No philosophers. No spaghetti!"

/*
** Actions and States definitions.
*/

# define THINKING 0
# define SLEEPING 1
# define EATING 2
# define PICK_LEFT_FORK 3
# define PICK_RIGHT_FORK 4
# define DROP_LEFT_FORK 5
# define DROP_RIGHT_FORK 6
# define FINISHED_EATING 7
# define DEAD 8

typedef struct s_rules
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals_per_philo;
}				t_rules;

int		check_args_errors(int argc, char **argv);
void	init_rules(char **argv, t_rules *rules);

#endif
