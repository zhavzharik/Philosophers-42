/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/12/01 21:56:23 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 3);
	check_time(philo, 2);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 4);
	// if (philo->odd == 1) // if use strategy left-handed and right-handed philo
	// 	usleep(1000);
}

void	philo_routine(t_philo *philo)
{
	if (philo->pos % 2 == 0)
		usleep(philo->t_to_eat);
	while (philo->life == 1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(999);
	}
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	ft_semaphore_init(data);
	monitor_create(data);
	philo_process(data);
	monitor_join(data);
	return (0);
}
