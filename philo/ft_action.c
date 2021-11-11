/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/11 21:02:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, 1);
	pthread_mutex_lock(philo->r_fork);
	philo_print(philo, 2);
	philo_print(philo, 3);
	philo->nb_eat++;
	philo->check_time = get_timestamp();
	usleep((philo->t_to_eat) * 1000);
	if (philo->nb_eat == philo->times_eat && philo->times_eat > 0)
		philo->hungry = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	philo_sleep(t_philo *philo)
{
	philo_print(philo, 4);
	usleep((philo->t_to_sleep) * 1000);
}

static void	philo_think(t_philo *philo)
{
	philo_print(philo, 5);
	// usleep(10);
}

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos % 2)
		usleep(100);
	while (g_life) //philo->must_live)
	{
		philo_eat(philo);
		philo_check_life(philo);
		if (!g_life) //philo->must_live)
			return (NULL);
		philo_sleep(philo);
		philo_check_life(philo);
		if (!g_life) //philo->must_live)
			return (NULL);
		philo_think(philo);
		if (!g_life) //philo->must_live)
			return (NULL);
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
