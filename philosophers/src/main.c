/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:21:02 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/07 19:20:02 by lniehues         ###   ########.fr       */
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

	TO-DO:
	- init pthreads philos
	- init mutexes (forks and print-lock)
	- create routine (and sobs eat, think and sleep)
	- utils for time check
*/

void	*routine()
{
	printf("Test from threads\n");
	sleep(2);
	printf("End thread\n");
	return ((void *)1);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;
	t_rules		rules;

	if (check_args_errors(argc, argv))
		return (1);
	init_rules(argv, &rules);
	if (argc && *argv)
	{
		if (pthread_create(&t1, NULL, &routine, NULL) != 0)
			printf("Deu ruim no 1!\n");
		if (pthread_create(&t2, NULL, &routine, NULL) != 0)
			printf("Deu ruim no 2!\n");
		if (pthread_join(t1, NULL) != 0)
			printf("Deu ruim no 1!\n");
		if (pthread_join(t2, NULL) != 0)
			printf("Deu ruim no 2!\n");
	}
	return (0);
}
