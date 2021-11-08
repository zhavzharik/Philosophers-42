/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/08 21:25:33 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	philo->check_time = get_timestamp();
	if (philo->data->everyone_ate != 1)
	{
		if (philo->pos % 2)
			usleep(15000);
		while (!philo->data->somebody_dead)
		{
			philo_eat(philo);
			check_everyone_ate(philo);
			// printf("Everyone_ate = %d\n", philo->data->everyone_ate);
			if (philo->data->everyone_ate == 1)
				break ;
			philo_sleep_think(philo);
			check_everyone_ate(philo);
		}
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
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
	while (i < data->nb_philo)
	{
		if (pthread_join(data->thinker[i].philo_thread, NULL) != 0)
			put_error_message(data, 5);
		i++;
	}
}
