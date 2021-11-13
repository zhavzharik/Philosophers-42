/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:59:57 by abridger          #+#    #+#             */
/*   Updated: 2021/11/13 23:32:23 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long long	get_time(t_philo *philo)
{
	long long	answer;

	answer = get_timestamp() - philo->start_time;
	return (answer);
}

void	philo_print(t_philo *philo, int message)
{
	pthread_mutex_lock(philo->message);
	if (message == 1)
		printf("%lli %d has taken a left fork\n", get_time(philo), philo->pos);
	else if (message == 2)
		printf("%lli %d has taken a right fork\n", get_time(philo), philo->pos);
	else if (message == 3)
		printf("%lli %d is eating\n", get_time(philo), philo->pos);
	else if (message == 4)
		printf("%lli %d is sleeping\n", get_time(philo), philo->pos);
	else if (message == 5)
		printf("%lli %d is thinking\n", get_time(philo), philo->pos);
	else if (message == 6)
		printf("%lli %d died\n", get_time(philo), philo->pos);
	pthread_mutex_unlock(philo->message);
}

void	*program_print(t_data *data, int message)
{
	pthread_mutex_lock(&data->put_message);
	if (message == 7)
	{
		printf("Someone dead. The simulation stops!\n");
	}
	else if (message == 8)
	{
		printf("All the philosopher has eaten at least %d times each!\n",
			data->nb_times_eat);
		printf("The simulation stops!\n");
	}
	return (NULL);
}
