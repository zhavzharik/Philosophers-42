/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:04:42 by abridger          #+#    #+#             */
/*   Updated: 2021/12/08 15:55:42 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 3);
	check_time(philo, 2);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 4);
}

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (philo->life == 1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(999);
	}
	return (NULL);
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	ft_mutex_init(data);
	start_philo_threads(data);
	return (0);
}
