/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/16 23:19:34 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	if (philo->hungry == 1)
	{
		if (philo->pos % 2 == 0 || (philo->pos % 2 == 1 && philo->last == 1))
		{
			pthread_mutex_lock(philo->l_fork);
			philo_print(philo, 1);
			pthread_mutex_lock(philo->r_fork);
			philo_print(philo, 1);
		}
		else if (philo->pos % 2 == 1 && philo->last != 1)
		{
			pthread_mutex_lock(philo->r_fork);
			philo_print(philo, 1);
			pthread_mutex_lock(philo->l_fork);
			philo_print(philo, 1);
		}
		// philo_print(philo, 2);
		philo->check_time = get_timestamp();
		philo_print(philo, 2);
		philo->nb_eat++;
		// if (philo->nb_eat == philo->times_eat && philo->times_eat > 0)
		// 	philo->hungry = 0;
		check_time(philo, 1);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		// check_philo_life(philo);
	}
}

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 3);
	check_time(philo, 2);
	// check_philo_life(philo);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 4);
	// check_philo_life(philo);
}

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos % 2)
		usleep(10000);
	while (philo->life == 1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
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
