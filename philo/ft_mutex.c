/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:14:30 by abridger          #+#    #+#             */
/*   Updated: 2021/11/07 22:16:00 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (0);	
}