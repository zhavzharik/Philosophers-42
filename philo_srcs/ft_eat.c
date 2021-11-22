/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:04:42 by abridger          #+#    #+#             */
/*   Updated: 2021/11/22 19:18:24 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_take_forks(t_philo *philo)
{
	if (philo->pos % 2 == 1 && philo->last_odd != 1)
	{
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, 1);
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, 1);
	}
	else if (philo->pos % 2 == 0 || philo->last_odd == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, 1);
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, 1);
	}
}

static void	philo_put_forks(t_philo *philo)
{
	if (philo->pos % 2 == 1 && philo->last_odd != 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else if (philo->pos % 2 == 0 || philo->last_odd == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	philo->prev_time = philo->check_time;
	philo->check_time = get_timestamp();
	// check_philo_life(philo);
	philo_print(philo, 2);
	philo->nb_eat++;
	check_time(philo, 1);
	philo_put_forks(philo);
}
