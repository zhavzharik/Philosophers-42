/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:04:42 by abridger          #+#    #+#             */
/*   Updated: 2021/12/03 17:14:16 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	philo_take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	philo_print(philo, 1);
	sem_wait(philo->data->forks);
	philo_print(philo, 1);
}

static void	philo_put_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	philo->prev_time = philo->check_time;
	philo->check_time = get_timestamp();
	philo_print(philo, 2);
	philo->nb_eat++;
	if (philo->data->nb_times_eat > 0
		&& philo->nb_eat == philo->data->nb_times_eat)
		sem_post(philo->data->sem_meal);
	check_time(philo, 1);
	philo_put_forks(philo);
}
