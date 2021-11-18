/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:14:47 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/17 21:21:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

__uint64_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (__uint64_t)1000 + time.tv_usec / (__uint64_t)1000);
}

long long int	timestamp(long long int session_start)
{
	return (get_current_time() - session_start);
}

void	wait_time_in_ms(long long int microseconds_time)
{
	usleep(microseconds_time * 1000);
}