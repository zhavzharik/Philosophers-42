/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:03:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/11 17:27:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	waiter;

	memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
		put_error_message(&data, 1);
	else
	{
		action(&data, argv);
		monitor(&waiter, &data);
		pthread_detach(waiter);
		join_philo_threads(&data);
		ft_all_clear(&data);
	}
	return (0);
}
