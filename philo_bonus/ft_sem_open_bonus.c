/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:14:30 by abridger          #+#    #+#             */
/*   Updated: 2021/12/01 21:38:30 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_semaphore_init(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/meal");
	// sem_unlink("/end");
	data->forks = sem_open("/forks", O_CREAT, 0664, data->nb_philo);
	if (data->forks == SEM_FAILED)
		exit(EXIT_FAILURE);
	data->put_message = sem_open("/message", O_CREAT, 0664, 1);
	if (data->put_message == SEM_FAILED)
		exit(EXIT_FAILURE);
	data->times_meal = sem_open("/meal", O_CREAT, 0664, 0);
	if (data->times_meal == SEM_FAILED)
		exit(EXIT_FAILURE);
	// data->end = sem_open("/end", O_CREAT, 0664, 0);
	// if (data->end == SEM_FAILED)
	// 	exit(EXIT_FAILURE);
	return (0);
}
