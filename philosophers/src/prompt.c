/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:28:51 by lniehues          #+#    #+#             */
/*   Updated: 2021/12/05 13:33:55 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*choose_type_color(int type)
{
	if (type == EATING)
		return (BOLD_BLUE);
	if (type == SLEEPING)
		return (BOLD_YELLOW);
	if (type == THINKING)
		return (BOLD_GREEN);
	if (type == SATIATED)
		return (BOLD_PURPLE);
	if (type == PICK_LEFT_FORK)
		return (ITALIC_YELLOW);
	if (type == PICK_RIGHT_FORK)
		return (ITALIC_BLUE);
	if (type == RELEASE_LEFT_FORK)
		return (ITALIC_CYAN);
	if (type == RELEASE_RIGHT_FORK)
		return (ITALIC_GREEN);
	if (type == DEAD)
		return (BOLD_RED);
	return (BOLD_WHITE);
}

static void	event_message_picker(int type, t_philo *philo)
{
	int	philo_index;

	philo_index = philo->index;
	if (type == EATING)
		printf("%d is eating. Yummy!\n", philo_index);
	else if (type == SLEEPING)
		printf("%d is taking a little nap...zzZ\n", philo_index);
	else if (type == THINKING)
		printf("%d is doing what philosophers do. Thinking!\n", philo_index);
	else if (type == SATIATED)
		printf("%d ate %d meals and with no space in his tummy!\n",
			philo_index, philo->meals_eaten);
	else if (type == PICK_LEFT_FORK)
		printf("%d took a fork in his left hand.\n", philo_index);
	else if (type == PICK_RIGHT_FORK)
		printf("%d took a fork in his right hand.\n", philo_index);
	else if (type == RELEASE_LEFT_FORK)
		printf("%d released his left fork.\n", philo_index);
	else if (type == RELEASE_RIGHT_FORK)
		printf("%d released his right fork.\n", philo_index);
	else if (type == DEAD)
		printf("%d is dead. R.I.P\n", philo_index);
}

void	philo_speak(long long int timestamp, int type, t_philo *philo)
{
	if (type != DEAD && *philo->is_dead)
		return ;
	printf("%s", choose_type_color(type));
	printf("% 10lld | ", timestamp);
	event_message_picker(type, philo);
	printf("%s", RESET_COLOR);
}
