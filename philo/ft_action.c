/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/07 22:58:17 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	philo->check_time = get_timestamp();
	printf("Time_stamp %lli\n", philo->check_time);
	pthread_mutex_lock(&philo->data->forks[philo->l_fork - 1]);
	pthread_mutex_lock(&philo->data->put_message);
	printf("%lli ms philosopher number %d has taken a left fork\n", get_timestamp(), philo->pos);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork - 1]);
	printf("%lli ms philosopher number %d has taken a right fork\n", get_timestamp(), philo->pos);
	pthread_mutex_lock(&philo->data->is_hungry);
	printf("%lli ms philosopher number %d is eating\n", get_timestamp(), philo->pos);
	philo->nb_eat++;
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->is_hungry);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork - 1]);
	printf("%lli ms philosopher number %d is sleeping\n", get_timestamp(), philo->pos);	
	pthread_mutex_unlock(&philo->data->put_message);
	usleep(philo->data->time_to_sleep);
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