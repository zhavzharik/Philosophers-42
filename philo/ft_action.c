/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/15 21:40:13 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	if (philo->hungry == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, 1);
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, 1);
		philo_print(philo, 2);
		philo->nb_eat++;
		philo->check_time = get_timestamp();
		check_time(philo, philo->t_to_eat);
		if (philo->nb_eat == philo->times_eat && philo->times_eat > 0)
			philo->hungry = 0;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		check_philo_life(philo);
	}
}

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 3);
	check_time(philo, philo->t_to_sleep);
	check_philo_life(philo);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 4);
	check_philo_life(philo);
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
