/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/06 23:57:41 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philo)
{
	t_philo	*philosopher;
	
	philosopher = (t_philo *)philo;
	philosopher->check_time = get_timestamp();
	if (philosopher->pos % 2 == 0)
		usleep(10000);
	printf("Position in routine: %d\n", philosopher->pos);
	printf("Left fork in routine: %d\n", philosopher->l_fork);
	printf("Right fork in routine: %d\n", philosopher->r_fork);
	return (0);
}

void	start_threads(t_data *data)
{
	int		i;
	t_philo	*philosopher;

	i = 0;
	while ( i < data->nb_philo)
	{
		philosopher = &(data->thinker[i]);
		if (pthread_create((&philosopher->philo_thread), 
			NULL, &routine, (void *)philosopher) != 0)
			put_error_message(data, 4);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while ( i < data->nb_philo)
	{
		if (pthread_join(data->thinker[i].philo_thread, 
			NULL) != 0)
			put_error_message(data, 5);
		i++;
	}
}