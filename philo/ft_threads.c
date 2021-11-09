/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/09 22:12:26 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->pos % 2)
		usleep(100);
	while (philo->data->everyone_ate != 1 && !philo->data->somebody_dead)
	{
		philo_eat(philo);
		check_everyone_ate(philo);
		printf("Everyone_ate = %d\n", philo->data->everyone_ate);
		if (philo->data->everyone_ate == 1)
			return (NULL); //break ;
		// philo_sleep_think(philo);
		// check_everyone_ate(philo);
		if (available_forks(philo) == 1 && philo->data->everyone_ate != 1)
			philo_eat(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo) // && data->everyone_ate != 1)
	{
		if (pthread_create((&(data->thinker[i]).philo_thread),
				NULL, &philo_routine, &(data->thinker[i])) != 0)
			put_error_message(data, 4);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo) // && data->everyone_ate != 1)
	{
		if (pthread_join(data->thinker[i].philo_thread, NULL) != 0)
			put_error_message(data, 5);
		i++;
	}
}
