/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:04:37 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/29 21:40:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_rules(char **argv, t_rules *rules)
{
	rules->num_of_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->num_of_meals_per_philo = ft_atoi(argv[5]);
	else
		rules->num_of_meals_per_philo = 0;
}

static void	init_philos(t_session *session)
{
	int	i;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		session->philos[i].index = i + 1;
		session->philos[i].is_dead = &session->is_dead;
		session->philos[i].dead_philo_index = &session->dead_philo_index;
		session->philos[i].time_of_death = &session->time_of_death;
		session->philos[i].meals_eaten = 0;
		session->philos[i].last_meal = 0;
		session->philos[i].left_fork = &session->forks[i];
		session->philos[i].right_fork = &session->forks[(i + 1)
			% session->rules->num_of_philos];
		session->philos[i].rules = session->rules;
		session->philos[i].session_start = session->session_start;
		session->philos[i].end_checker = &session->end_checker;
		session->philos[i].print_lock = &session->print_lock;
		i++;
	}
}

static void	init_forks(t_session *session)
{
	int	i;

	i = 0;
	while (i < session->rules->num_of_philos)
	{
		pthread_mutex_init(&session->forks[i], NULL);
		i++;
	}
}

void	init_session(t_session *session, t_rules *rules)
{
	pthread_t		threads[200];

	pthread_mutex_init(&session->end_checker, NULL);
	pthread_mutex_init(&session->print_lock, NULL);
	session->rules = rules;
	session->session_start = get_current_time();
	session->time_of_death = 0;
	session->is_dead = 0;
	session->dead_philo_index = 0;
	init_forks(session);
	init_philos(session);
	create_philo_threads(threads, session);
	join_philo_threads(threads, session);
}
