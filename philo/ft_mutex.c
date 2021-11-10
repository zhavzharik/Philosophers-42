/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:14:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/10 16:39:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	ft_define_philo_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].l_fork = &(data->forks[i]);
		data->thinker[i].r_fork = &(data->forks[(i + 1) % data->nb_philo]);
		data->thinker[i].hungry = &(data->is_hungry);
		data->thinker[i].message = &(data->put_message);
		i++;
	}
	return (0);
}

int	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (put_error_message(data, 6));
		i++;
	}
	if (pthread_mutex_init(&data->is_hungry, NULL) != 0)
		return (put_error_message(data, 6));
	if (pthread_mutex_init(&data->put_message, NULL) != 0)
		return (put_error_message(data, 6));
	return (ft_define_philo_mutex(data));
}
