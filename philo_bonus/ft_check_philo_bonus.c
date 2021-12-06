/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/12/06 21:58:32 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_everyone_ate(void *info)
{
	int		check;
	t_data	*data;

	check = 0;
	data = (t_data *)info;
	if (data->nb_times_eat > 0)
	{
		while (data->end == 0)
		{
			sem_wait(data->sem_meal);
			check++;
			if (check == data->nb_times_eat)
			{
				data->everyone_ate = 1;
				program_print(data, 6, 1); // 1 not need?
				data->end = 1;
				break ;
			}
		}
	}
	return (NULL);
}

void	*philo_status(void *philosopher)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)philosopher;
	while (philo->life == 1)
	{
		check = (int)(philo->check_time - philo->prev_time);
		if (check == 0)
			check = get_timestamp() - philo->prev_time;
		if (check > philo->t_to_die)
		{
			philo->death_time = get_timestamp();
			philo_print(philo, 5);
			philo->life = 0;
			philo->data->end = 1;
		}
		usleep(100);
	}
	return (NULL);
}

void	*game_end(void *info)
{
	t_data	*data;
	int		i;

	data = (t_data *)info;
	i = -1;
	sem_wait(data->sem_end);
	data->end = 1;
	while (++i < data->nb_philo)
	{
		kill(data->thinker[i].pid, SIGKILL);
	}
	return (NULL);
}
