/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:03:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/15 22:44:02 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	waiter;
	int			result;

	// memset(&data, 0, sizeof(t_data));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	result = 1;
	if (argc != 5 && argc != 6)
		return (put_error_message(data, 1));
	else
	{
		result = action(data, argv);
		detach_philo_threads(data);
		monitor(&waiter, data);
		if (pthread_join(waiter, NULL) != 0)
			return (put_error_message(data, 5));
		ft_all_clear(data);
	}
	return (result);
}
