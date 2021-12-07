/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/12/07 20:09:53 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create((&(data->thinker[i]).philo_thread),
				NULL, &philo_routine, &(data->thinker[i])) != 0)
			put_error_message(data, 4);
		i += 2;
	}
	usleep(data->time_to_eat);
	i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create((&(data->thinker[i]).philo_thread),
				NULL, &philo_routine, &(data->thinker[i])) != 0)
			put_error_message(data, 4);
		i += 2;
	}
}

void	detach_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_detach(data->thinker[i].philo_thread) != 0)
			put_error_message(data, 7);
		i++;
	}
}

void	monitor(pthread_t *waiter, t_data *data)
{
	if (pthread_create(waiter, NULL,
			&philo_status, (void *)data) != 0)
		put_error_message(data, 4);
}
