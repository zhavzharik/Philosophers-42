/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:59:57 by abridger          #+#    #+#             */
/*   Updated: 2021/11/25 20:37:18 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long long	get_time(t_philo *philo, int check)
{
	long long	answer;

	if (check == 1)
		answer = get_timestamp() - philo->start_time;
	if (check == 2)
		answer = philo->death_time - philo->start_time;
	return (answer);
}

void	philo_print(t_philo *philo, int message)
{
	long long	timing;

	timing = philo->check_time - philo->start_time;
	pthread_mutex_lock(philo->message);
	if (message == 1 && philo->life == 1)
		printf("%lli %d has taken a fork\n",
			get_time(philo, 1), philo->pos);
	else if (message == 2 && philo->life == 1)
		printf("%lli %d is eating\n", timing, philo->pos);
	else if (message == 3 && philo->life == 1)
		printf("%lli %d is sleeping\n", timing + philo->t_to_eat, philo->pos);
	else if (message == 4 && philo->life == 1)
		printf("%lli %d is thinking\n",
			timing + philo->t_to_eat + philo->t_to_sleep, philo->pos);
	pthread_mutex_unlock(philo->message);
}

void	*program_print(t_data *data, int message, int i)
{
	pthread_mutex_lock(&data->put_message);
	if (message == 5)
	{
		printf("%lli %d died.\nThe simulation stops!\n",
			get_time(&(data->thinker[i]), 2), data->thinker[i].pos);
	}
	else if (message == 6)
	{
		printf("All the philosopher has eaten at least %d times each!\n",
			data->nb_times_eat);
		printf("The simulation stops!\n");
	}
	pthread_mutex_unlock(&data->put_message);
	return (NULL);
}
