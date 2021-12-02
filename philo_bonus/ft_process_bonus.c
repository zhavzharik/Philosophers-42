/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/12/02 22:39:29 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	wait_philo_process(t_data *data)
{
	int		i;
	int		status;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < data->nb_philo)
			{
				kill(data->thinker[i].pid, 15);
			}
		}
		i++;
	}
	if (data->end == 1)
		exit(0);
}

void	philo_process(t_data *data)
{
	int			i;
	pthread_t	checker;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].pid = fork();
		if (data->thinker[i].pid == -1)
			exit (EXIT_FAILURE);
		else if (data->thinker[i].pid == 0)
		{
			if (pthread_create(&(checker), NULL,
					&philo_status, &(data->thinker[i])) != 0)
				put_error_message(data, 4);
			if (pthread_detach(checker) != 0)
				put_error_message(data, 7);
			philo_routine(&(data->thinker[i]));
			// if (pthread_join(checker, NULL) != 0)
			// 	put_error_message(data, 5);
		}
		i++;
	}
	wait_philo_process(data);
}

void	monitor_create(t_data *data)
{
	if (pthread_create(&(data->waiter), NULL, &game_end, (void *)data) != 0)
		put_error_message(data, 4);
}

// void	monitor_join(t_data *data)
// {
// 	if (pthread_join(data->waiter, NULL) != 0)
// 		put_error_message(data, 5);
// }

void	monitor_detach(t_data *data)
{
	if (pthread_detach(data->waiter) != 0)
		put_error_message(data, 7);
}
