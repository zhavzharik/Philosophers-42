/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/12/10 20:41:30 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_everyone_ate(void *info)
{
	int		check;
	t_data	*data;

	check = 0;
	data = (t_data *)info;
	while (data->end == 0)
	{
		sem_wait(data->sem_meal);
		check++;
		if (check == data->nb_philo)
		{
			data->everyone_ate = 1;
			program_print(data);
			return (ft_kill_process(data));
		}
	}
	return (NULL);
}

void	*philo_status(void *philosopher)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)philosopher;
	while (philo->life == 1 && philo->data->end == 0)
	{
		check = (int)(philo->check_time - philo->prev_time);
		if (check == 0 && philo->data->end == 0)
			check = get_timestamp() - philo->prev_time;
		if (check > philo->t_to_die && philo->data->end == 0)
		{
			philo->death_time = get_timestamp();
			philo_print_death(philo);
			sem_post(philo->data->sem_end);
			philo->life = 0;
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
		data->thinker[i].life = 0;
	return (ft_kill_process(data));
}
