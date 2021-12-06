/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/12/06 22:00:04 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	philo_sleep(t_philo *philo)
{
	if (philo->data->end == 0)
	{
		philo_print(philo, 3);
		check_time(philo, 2);
	}
}

static void	philo_think(t_philo *philo)
{
	if (philo->data->end == 0)
	{
		philo_print(philo, 4);
	}
}

void	philo_routine(t_philo *philo)
{
	pthread_t	checker;

	if (pthread_create(&(checker), NULL, &philo_status, philo) != 0)
		put_error_message(philo->data, 4);
	if (pthread_detach(checker) != 0)
		put_error_message(philo->data, 7);
	while (philo->life == 1 && philo->data->end == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(999); // ?
	}
}

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	ft_semaphore_init(data);
	philo_process(data);
	return (0);
}
