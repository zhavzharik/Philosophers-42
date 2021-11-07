/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/07 22:39:31 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;
	
	philo = (t_philo *)philosopher;
	philo->check_time = get_timestamp();
	if (philo->pos % 2)
		usleep(15000);
	while (!philo->data->somebody_dead)
	{
		philo_eat(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int		i;
	//t_philo	*philosopher;

	i = 0;
	while ( i < data->nb_philo)
	{
		//philosopher = &(data->thinker[i]);
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