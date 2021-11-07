/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:37:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/07 21:04:20 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_input(t_data *data)
{
	if (data->nb_philo < 1 || data->time_to_die < 0 
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
	{
		return (put_error_message(data, 2));
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
		data->nb_times_eat = 0;
	data->somebody_dead = 0;
	if (check_input(data))
		return (1);
	else
		return (init_thinkers(data));
}

int	init_thinkers(t_data *data)
{
	int		i;

	i = data->nb_philo;
	data->thinker = (t_philo *)malloc(sizeof(t_philo) * i);
	if (!data->thinker)
		return (put_error_message(data, 3));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	if (!data->forks)
		return (put_error_message(data, 3));
	while (--i >= 0)
	{
		printf("i %d\n", i);
		data->thinker[i].pos = i + 1;
		data->thinker[i].l_fork = i + 1;
		if (i == data->nb_philo - 1)
			data->thinker[i].r_fork = (i + 2) % data->nb_philo;
		else
			data->thinker[i].r_fork = i + 2;
		data->thinker[i].nb_eat = 0;
		data->thinker[i].check_time = 0;
		data->thinker[i].data = data;
		printf("Position: %d\n", data->thinker[i].pos);
		printf("Left fork: %d\n", data->thinker[i].l_fork);
		printf("Right fork: %d\n", data->thinker[i].r_fork);
	}
	return (0);
}

