/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:04:42 by abridger          #+#    #+#             */
/*   Updated: 2021/12/08 17:50:55 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_print(philo, 1);
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, 1);
}

static void	philo_put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	philo->prev_time = philo->check_time;
	philo->check_time = get_timestamp();
	philo_print(philo, 2);
	check_time(philo, 1);
	philo_put_forks(philo);
	philo->nb_eat++;
}
