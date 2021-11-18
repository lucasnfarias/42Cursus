/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:34:46 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/17 21:51:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// background check if philo is dead
static void	end_checker_routine(void *philo_reference)
{
	t_philo		*philo;

	philo = (t_philo *)philo_reference;
	while (1)
	{
		if (philo->is_dead == 1)
			return ((void *)1);
		// check if is satiated and start satiation process
		// check if is about to die and start death process
	}
}

static void	routine (void *philo_reference)
{
	t_philo		*philo;
	pthread_t	*end_checker;

	philo = (t_philo *)philo_reference;
	if (pthread_create(&end_checker, NULL, &end_checker_routine, philo) != 0)
		return ((void *)1);
	pthread_detach(end_checker);
	if (philo->index % 2 == 0)
		usleep(6000);
	// while eating sleeping thinking continue
	return (NULL);
}

void	join_threads(pthread_t *threads, t_session *session)
{
	int	i;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

int	create_threads(pthread_t *threads, t_session *session)
{
	int		i;
	void	*current_philo;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		current_philo = (void *)(&session->philos[i]);
		if (pthread_create(&threads[i], NULL, &routine, current_philo) != 0)
			return (1);
		i++;
	}
	return (0);
}