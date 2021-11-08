/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:59:57 by abridger          #+#    #+#             */
/*   Updated: 2021/11/08 18:34:21 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_print(t_philo *philo, int message)
{
	pthread_mutex_lock(&philo->data->put_message);
	if (message == 1)
		printf("%lli %d has taken a left fork\n", get_timestamp(), philo->pos);
	else if (message == 2)
		printf("%lli %d has taken a right fork\n", get_timestamp(), philo->pos);
	else if (message == 3)
		printf("%lli %d is eating\n", get_timestamp(), philo->pos);
	else if (message == 4)
		printf("%lli %d is sleeping\n", get_timestamp(), philo->pos);
	else if (message == 5)
		printf("%lli %d is thinking\n", get_timestamp(), philo->pos);
	else if (message == 6)
		printf("%lli %d died\n", get_timestamp(), philo->pos);
	pthread_mutex_unlock(&philo->data->put_message);
}
