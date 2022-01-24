/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:34:46 by lniehues          #+#    #+#             */
/*   Updated: 2021/12/02 21:37:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_philo_threads(pthread_t *threads, t_session *session)
{
	int	i;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < session->rules->num_of_philos)
	{
		pthread_mutex_destroy(&(session->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(session->print_lock));
	pthread_mutex_destroy(&(session->end_checker));
}

int	create_philo_threads(pthread_t *threads, t_session *session)
{
	int				i;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &philo_routine,
				(void *)&session->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
