/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/11/10 23:23:39 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			if (data->thinker[i].nb_eat >= data->nb_times_eat)
				check++;
			// printf("Поел %d vs Надо %d\t I = % d\t Check = %d\n", data->thinker[i].nb_eat, data->nb_times_eat, i, check);
			if (check == data->nb_philo)
			{
				//data->everyone_ate = 1;
				i = 0;
				while (i < data->nb_philo)
				{
					data->thinker[i].must_live = 0;
					i++;
				}
			}
			i++;
		}
		// printf("everyone_ate %d\n", data->everyone_ate);
	}
}

static void	check_somebody_dead(t_data *data)
{
	int			i;
	long long	check;

	i = 0;
	// check = 0;
	while (i < data->nb_philo)
	{
		check = get_timestamp() - data->thinker[i].check_time;
		if (check > data->time_to_die)
		{
			//data->somebody_dead = 1;
			i = 0;
			while (i < data->nb_philo)
			{
				data->thinker[i].must_live = 0;
				i++;
			}
		}
		i++;
	}
	// printf("somebody_dead %d\n", data->somebody_dead);
}

void	*philo_status(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	while (1)
	{
		check_everyone_ate(data);
		// check_somebody_dead(data);
		if (data->everyone_ate == 1) // || data->somebody_dead == 1)
		{
			// pthread_mutex_lock(&data->put_message);
			ft_all_clear(data);
			break ;// return (NULL);
		}
		check_somebody_dead(data);
		if (data->somebody_dead == 1)
		{
			// pthread_mutex_lock(&data->put_message);
			ft_all_clear(data);
			break; //return (NULL);
		}
	}
	return (NULL);
}
