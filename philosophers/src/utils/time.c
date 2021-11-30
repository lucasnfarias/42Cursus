/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:14:47 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/29 21:42:48 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec
			* (long long int)1000)
		+ (time.tv_usec
			/ (long long int)1000));
}

long long int	timestamp(long long int session_start)
{
	return (get_current_time() - session_start);
}

void	wait_time_in_ms(long long int miliseconds_time)
{
	usleep(miliseconds_time * 1000);
}
