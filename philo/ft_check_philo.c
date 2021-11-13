/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/11/13 23:33:40 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	waiters_reset_lives(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].life = 0;
		i++;
	}
}

static void	check_everyone_ate(t_data *data)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (data->nb_times_eat > 0)
	{
		while (i < data->nb_philo)
		{
			if (data->thinker[i].hungry == 0)
				check++;
			if (check == data->nb_philo)
			{
				data->everyone_ate = 1;
				waiters_reset_lives(data);
			}
			i++;
		}
	}
}

static void	check_lives(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->thinker[i].life == 0)
		{
			waiters_reset_lives(data);
			data->end = 1;
		}
		i++;
	}
}

void	*philo_status(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	while (data->end == 0)
	{
		check_everyone_ate(data);
		check_lives(data);
		if (data->everyone_ate == 1)
		{
			waiters_reset_lives(data);
			return (program_print(data, 8));
		}
		else if (data->end == 1)
		{
			return (program_print(data, 7));
		}
	}
	return (NULL);
}

void	check_philo_life(t_philo *philo)
{
	long long	check;

	if (philo->life == 1)
	{
		check = get_timestamp() - philo->check_time;
		if (check > philo->t_to_die)
		{
			philo->life = 0;
			// philo_print(philo, 6);
			// pthread_mutex_lock(philo->message);
		}
	}
}
