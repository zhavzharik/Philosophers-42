/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/09 22:09:03 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	available_forks(t_philo *philo)
{
	int	*forks;

	forks = philo->data->occupied_forks;
	if (forks[philo->l_fork - 1] == 0 && forks[philo->r_fork - 1] == 0)
		return (1);
	else
		return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->everyone_ate != 1)
	{
		pthread_mutex_lock(&philo->data->is_hungry);
		pthread_mutex_lock(&philo->data->forks[philo->l_fork - 1]);
		philo_print(philo, 1);
		pthread_mutex_lock(&philo->data->forks[philo->r_fork - 1]);
		philo_print(philo, 2);
		philo_print(philo, 3);
		philo->nb_eat++;
		philo->data->occupied_forks[philo->l_fork - 1] = 1;
		philo->data->occupied_forks[philo->r_fork - 1] = 1;
		philo->check_time = get_timestamp();
		usleep((philo->data->time_to_eat) * 1000);
		pthread_mutex_unlock(&philo->data->is_hungry);
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork - 1]);
		philo_sleep_think(philo);
		check_everyone_ate(philo);
		if (available_forks(philo) == 1)
			philo_eat(philo);
	}
}

void	philo_sleep_think(t_philo *philo)
{
	if (philo->data->everyone_ate != 1)
	{
		philo_print(philo, 4);
		usleep((philo->data->time_to_sleep) * 1000);
		philo_print(philo, 5);
		usleep(10);
	}
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	ft_mutex_init(data);
	data->start_time = get_timestamp();
	start_threads(data);
	join_threads(data);
	return (0);
}
