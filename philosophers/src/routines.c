/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:13:10 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/29 21:41:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_satiated(t_philo *philo, t_rules *rules)
{
	if (rules->num_of_meals_per_philo > 0
		&& philo->meals_eaten
		== rules->num_of_meals_per_philo)
		return (1);
	return (0);
}

static void	satiation_process(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), philo->index, SATIATED,
		philo->meals_eaten);
	pthread_mutex_unlock(philo->print_lock);
}

static void	death_process(t_philo *philo)
{
	*philo->is_dead = 1;
	*philo->time_of_death = timestamp(philo->session_start);
	*philo->dead_philo_index = philo->index;
}

static void	*end_checker_routine(void *philo_ref)
{
	t_philo		*philo;
	t_rules		*rules;

	philo = (t_philo *)philo_ref;
	rules = philo->rules;
	while (1)
	{
		if (*philo->is_dead == 1)
			return ((void *)1);
		if (is_satiated(philo, rules))
		{
			satiation_process(philo);
			return ((void *)1);
		}
		if ((timestamp(philo->session_start) - philo->last_meal)
			> rules->time_to_die && *philo->is_dead == 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_lock(philo->end_checker);
			death_process(philo);
			pthread_mutex_unlock(philo->end_checker);
			return ((void *)1);
		}
	}
}

void	*philo_routine(void *philo_ref)
{
	t_philo			*philo;
	pthread_t		end_checker;

	philo = (t_philo *)philo_ref;
	if (pthread_create(&end_checker, NULL, &end_checker_routine,
			philo) != 0)
		return ((void *)1);
	pthread_detach(end_checker);
	if (philo->index % 2 == 0)
		wait_time_in_ms(6);
	while (eating(philo) && sleeping(philo)
		&& thinking(philo))
		continue ;
	return (NULL);
}
