/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/12/08 18:32:49 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_process(t_data *data)
{
	int			i;
	pthread_t	waiter_end;
	pthread_t	waiter_meal;

	i = 0;
	waiter_end = NULL;
	waiter_meal = NULL;
	monitor(waiter_end, waiter_meal, data);
	while (i < data->nb_philo)
	{
		data->thinker[i].pid = fork();
		if (data->thinker[i].pid == -1)
			exit (EXIT_FAILURE);
		else if (data->thinker[i].pid == 0)
		{
			philo_routine(&(data->thinker[i]));
		}
		i++;
		usleep(100);
	}
}

void	monitor(pthread_t waiter_end, pthread_t waiter_meal, t_data *data)
{
	if (pthread_create(&waiter_end, NULL, &game_end, (void *)data) != 0)
		put_error_message(data, 4);
	if (pthread_detach(waiter_end) != 0)
		put_error_message(data, 7);
	if (data->nb_times_eat > 0)
	{
		if (pthread_create(&waiter_meal, NULL,
				&check_everyone_ate, (void *)data) != 0)
			put_error_message(data, 4);
		if (pthread_detach(waiter_meal) != 0)
			put_error_message(data, 7);
	}
}
