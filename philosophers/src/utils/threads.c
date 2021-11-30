/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:34:46 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/29 18:57:13 by lniehues         ###   ########.fr       */
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
