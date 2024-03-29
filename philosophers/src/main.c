/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:21:02 by lniehues          #+#    #+#             */
/*   Updated: 2022/01/10 19:10:04 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	# EXT. FUNCS:
	memset, printf, malloc, free, write,
	usleep, gettimeofday, pthread_create,
	pthread_detach, pthread_join, pthread_mutex_init,
	pthread_mutex_destroy, pthread_mutex_lock,
	pthread_mutex_unlock

	# ARGUMENTS:
	arg 1: number_of_philosophers
	arg 2: time_to_die
	arg 3: time_to_eat
	arg 4: time_to_sleep
	arg 5: number_of_times_each_philosopher_must_eat (optional)
*/

int	main(int argc, char **argv)
{
	t_rules		rules;
	t_session	session;

	if (check_args_errors(argc, argv))
		return (1);
	init_rules(argv, &rules);
	init_session(&session, &rules);
	if (session.is_dead)
		philo_speak(session.time_of_death, DEAD,
			&session.philos[session.dead_philo_index - 1]);
	return (0);
}
