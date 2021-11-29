/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/29 21:38:27 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	detach_philo_thread(t_data *data, int i)
{
	if (pthread_detach(data->thinker[i].philo_thread) != 0)
		put_error_message(data, 7);
}

static void	monitor(t_data *data, int i)
{
	if (pthread_create((&(data->thinker[i]).waiter), NULL,
			&philo_status, &(data->thinker[i])) != 0)
		put_error_message(data, 4);
}

static void	start_philo_thread(t_data *data, int i)
{
	if (pthread_create((&(data->thinker[i]).philo_thread),
			NULL, &philo_routine, &(data->thinker[i])) != 0)
		put_error_message(data, 4);
}

static void	even_philo_process(t_data *data)
{
	int		i;

	i = 1;
	while (i < data->nb_philo)
	{
		data->thinker[i].pid = fork();
		if (data->thinker[i].pid == -1)
			exit (EXIT_FAILURE);
		if (data->thinker[i].pid != 0)
		{
			start_philo_thread(data, i);
			detach_philo_thread(data, i);
		}
		else
		{
			monitor(data, i);
			wait_waiter(data, i);
		}
		i += 2;
	}
}

void	philo_process(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].pid = fork();
		if (data->thinker[i].pid == -1)
			exit (EXIT_FAILURE);
		if (data->thinker[i].pid != 0)
		{
			start_philo_thread(data, i);
			detach_philo_thread(data, i);
		}
		else
		{
			monitor(data, i);
			wait_waiter(data, i);
		}
		i += 2;
	}
	usleep(data->time_to_eat);
	even_philo_process(data);
}
