/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/08 21:20:44 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		usleep((philo->data->time_to_eat) * 1000);
		//printf("%lli = Last meal %d philosopher\n", get_timestamp(), philo->pos);
		pthread_mutex_unlock(&philo->data->is_hungry);
		philo->check_time = get_timestamp();
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork - 1]);
	}
}

void	philo_sleep_think(t_philo *philo)
{
	if (philo->data->everyone_ate != 1)
	{
		philo_print(philo, 4);
		usleep((philo->data->time_to_sleep) * 1000);
		philo_print(philo, 5);
	}
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	data->start_time = get_timestamp();
	ft_mutex_init(data);
	start_threads(data);
	join_threads(data);
	return (0);
}
