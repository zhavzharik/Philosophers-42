/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:56:20 by abridger          #+#    #+#             */
/*   Updated: 2021/11/26 18:35:58 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_timestamp(void)
{
	struct timeval	tv;
	long long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_stamp);
}

void	check_time(t_philo *philo, int flag)
{
	int	difference;

	while (1)
	{
		usleep(50);
		difference = (int)(get_timestamp() - philo->check_time);
		if (philo->life == 0)
			break ;
		if (flag == 1 && difference >= philo->t_to_eat)
			break ;
		else if (flag == 2
			&& difference >= (philo->t_to_eat + philo->t_to_sleep))
			break ;
	}
}
