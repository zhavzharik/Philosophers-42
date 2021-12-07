/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:37:40 by abridger          #+#    #+#             */
/*   Updated: 2021/12/07 20:20:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_malloc_philo(t_data *data)
{
	int		i;

	i = data->nb_philo;
	data->thinker = (t_philo *)malloc(sizeof(t_philo) * i);
	if (!data->thinker)
		return (put_error_message(data, 3));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	if (!data->forks)
		return (put_error_message(data, 3));
	return (0);
}

static int	init_thinkers(t_data *data)
{
	int		i;

	i = data->nb_philo;
	ft_malloc_philo(data);
	data->start_time = get_timestamp();
	while (--i >= 0)
	{
		data->thinker[i].pos = i + 1;
		data->thinker[i].t_to_die = data->time_to_die;
		data->thinker[i].t_to_eat = data->time_to_eat;
		data->thinker[i].t_to_sleep = data->time_to_sleep;
		data->thinker[i].nb_eat = 0;
		data->thinker[i].check_time = data->start_time;
		data->thinker[i].prev_time = data->start_time;
		data->thinker[i].start_time = data->start_time;
		data->thinker[i].death_time = 0;
		data->thinker[i].life = 1;
	}
	return (0);
}

int	put_input(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_times_eat = ft_atoi(argv[5]);
	else
		data->nb_times_eat = -1;
	data->everyone_ate = 0;
	data->end = 0;
	return (init_thinkers(data));
}
