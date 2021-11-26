/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/11/26 18:46:43 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
			if (data->thinker[i].nb_eat == data->nb_times_eat
				&& data->nb_times_eat > 0)
			{
				check++;
			}
			if (check == data->nb_philo)
			{
				data->everyone_ate = 1;
			}
			i++;
		}
	}
}

static int	check_lives(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	while (i < data->nb_philo)
	{
		check = (int)(data->thinker[i].check_time - data->thinker[i].prev_time);
		if (check == 0)
			check = get_timestamp() - data->thinker[i].prev_time;
		if (check > data->time_to_die)
		{
			data->thinker[i].life = 0;
			data->thinker[i].death_time = get_timestamp();
			data->end = 1;
			return (i);
		}
		i++;
	}
	return (0);
}

void	*philo_status(void *info)
{
	t_data	*data;
	int		i;

	data = (t_data *)info;
	while (data->end == 0)
	{
		check_everyone_ate(data);
		i = check_lives(data);
		if (data->everyone_ate == 1)
		{
			waiters_reset_lives(data);
			return (program_print(data, 6, 1));
		}
		else if (data->end == 1)
		{
			waiters_reset_lives(data);
			return (program_print(data, 5, i));
		}
	}
	return (NULL);
}
