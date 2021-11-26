/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:14:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/26 21:28:03 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	int	ft_define_philo_semaphore(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].l_fork = &(data->forks[i]);
		data->thinker[i].r_fork = &(data->forks[(i + 1) % data->nb_philo]);
		data->thinker[i].message = &(data->put_message);
		i++;
	}
	return (0);
}

int	ft_semaphore_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i] = sem_open("/semaphor", O_CREAT, 0666, 1);
		if (data->forks[i] == SEM_FAILED)
			exit(EXIT_FAILURE);
		i++;
	}
	data->put_message = sem_open("/message", O_CREAT, 0666, 1);
	if (data->put_message == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (ft_define_philo_semaphore(data));
}
