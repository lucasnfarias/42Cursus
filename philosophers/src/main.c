/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:21:02 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/31 19:57:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void*	routine()
{
	printf("Test from threads\n");
	sleep(2);
	printf("End thread\n");
	return ((void*)1);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

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
