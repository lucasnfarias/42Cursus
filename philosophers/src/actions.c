/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:12:41 by lniehues          #+#    #+#             */
/*   Updated: 2021/12/05 13:37:20 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	aggressively_pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), PICK_LEFT_FORK, philo);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), PICK_RIGHT_FORK, philo);
	pthread_mutex_unlock(philo->print_lock);
	philo->last_meal = timestamp(philo->session_start);
}

static void	calmly_release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), RELEASE_LEFT_FORK, philo);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), RELEASE_RIGHT_FORK, philo);
	pthread_mutex_unlock(philo->print_lock);
	philo->meals_eaten += 1;
}

int	eating(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	if (*philo->is_dead == 1 || is_satiated(philo, rules) == 1)
		return (0);
	aggressively_pick_up_forks(philo);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), EATING, philo);
	pthread_mutex_unlock(philo->print_lock);
	wait_time_in_ms(rules->time_to_eat);
	calmly_release_forks(philo);
	return (1);
}

int	sleeping(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	if (*philo->is_dead == 1 || is_satiated(philo, rules) == 1)
		return (0);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), SLEEPING, philo);
	pthread_mutex_unlock(philo->print_lock);
	wait_time_in_ms(rules->time_to_sleep);
	return (1);
}

int	thinking(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	if (*philo->is_dead == 1 || is_satiated(philo, rules) == 1)
		return (0);
	pthread_mutex_lock(philo->print_lock);
	philo_speak(timestamp(philo->session_start), THINKING, philo);
	pthread_mutex_unlock(philo->print_lock);
	return (1);
}
