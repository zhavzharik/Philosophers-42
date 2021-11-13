/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/13 23:31:16 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	if (philo->hungry == 1) //&& philo->life == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, 1);
		// check_philo_life(philo);
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, 2);
		// check_philo_life(philo);
		philo_print(philo, 3);
		philo->nb_eat++;
		philo->check_time = get_timestamp();
		usleep((philo->t_to_eat) * 1000); // rewrite
		if (philo->nb_eat == philo->times_eat && philo->times_eat > 0)
			philo->hungry = 0;
		// check_philo_life(philo);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		check_philo_life(philo);
	}
}

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 4);
	usleep((philo->t_to_sleep) * 1000); // rewrite
	check_philo_life(philo);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 5);
	check_philo_life(philo);
}

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos % 2)
		usleep(100);
	while (philo->life == 1)
	{
		philo_eat(philo);
		if (philo->life == 0)
			return (NULL);
		philo_sleep(philo);
		if (philo->life == 0)
			return (NULL);
		philo_think(philo);
		if (philo->life == 0)
			return (NULL);
	}
	return (0);
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	ft_mutex_init(data);
	start_philo_threads(data);
	return (0);
}
