/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:14:30 by abridger          #+#    #+#             */
/*   Updated: 2021/12/03 17:22:14 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_semaphore_init(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/meal");
	sem_unlink("/end");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->nb_philo);
	if (data->forks == SEM_FAILED)
		exit(EXIT_FAILURE);
	data->put_message = sem_open("/message", O_CREAT, 0644, 1);
	if (data->put_message == SEM_FAILED)
		exit(EXIT_FAILURE);
	data->sem_meal = sem_open("/meal", O_CREAT, 0644, 0);
	if (data->sem_meal == SEM_FAILED)
		exit(EXIT_FAILURE);
	data->sem_end = sem_open("/end", O_CREAT, 0644, 0);
	if (data->sem_end == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (0);
}
