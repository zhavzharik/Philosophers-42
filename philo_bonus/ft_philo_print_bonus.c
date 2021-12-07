/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:59:57 by abridger          #+#    #+#             */
/*   Updated: 2021/12/07 18:22:21 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	sem_wait(philo->data->put_message);
	if (message == 1 && philo->life == 1 && philo->data->end == 0)
		printf("%lli %d has taken a fork\n",
			get_time(philo, 1), philo->pos);
	else if (message == 2 && philo->life == 1 && philo->data->end == 0)
		printf("%lli %d is eating\n", timing, philo->pos);
	else if (message == 3 && philo->life == 1 && philo->data->end == 0)
		printf("%lli %d is sleeping\n", timing + philo->t_to_eat, philo->pos);
	else if (message == 4 && philo->life == 1 && philo->data->end == 0)
		printf("%lli %d is thinking\n",
			timing + philo->t_to_eat + philo->t_to_sleep, philo->pos);
	else if (message == 5)
	{
		printf("%lli %d died.\nThe simulation stops!\n",
			get_time(philo, 2), philo->pos);
		sem_post(philo->data->sem_end);
	}
	sem_post(philo->data->put_message);
}

void	program_print(t_data *data)
{
	sem_wait(data->put_message);
	if (data->end == 0)
	{
		printf("All the philosopher has eaten at least %d times each!\n",
			data->nb_times_eat);
		printf("The simulation stops!\n");
		sem_post(data->sem_end);
	}
	sem_post(data->put_message);
}
