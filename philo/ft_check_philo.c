/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/11/11 21:03:18 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_everyone_ate(t_data *data)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (data->nb_times_eat > 0)
	{
		while (i < data->nb_philo)
		{
			if (data->thinker[i].hungry == 0)
				check++;
			// printf("CHECK = %d\n", check);
			if (check == data->nb_philo)
			{
				data->everyone_ate = 1;
				g_life = 0;
				// data->life = 0;
				break ;
			}
			i++;
		}
	}
}

// static void	check_life(t_data *data)
// {
// 	int			i;
// 	long long	check;

// 	i = 0;
// 	while (i < data->nb_philo)
// 	{
// 		check = get_timestamp() - data->thinker[i].check_time;
// 		// printf("CHECK life %lld\t input %d\n", check, data->time_to_die);
// 		// printf("philo time life %lld\n", data->thinker[i].check_time);
// 		if (check > data->time_to_die)
// 		{
// 			g_life = 0;
// 			philo_print(&(data->thinker[i]), 6);
// 			break ;
// 		}
// 		i++;
// 	}
// }

void	*philo_status(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	// usleep(10000);
	while (!data->everyone_ate || !g_life)
	{
		check_everyone_ate(data);
		// check_life(data);
		// printf("CHECK_every_one_ate = %d\n", data->everyone_ate);
		if (data->everyone_ate == 1 && g_life == 0)
		{
			program_print(data, 8);
			// pthread_mutex_lock(&data->put_message);
			// ft_all_clear(data);
			return (NULL);
		}
		else if (g_life == 0 && data->everyone_ate == 0)
		{
			// pthread_mutex_lock(&data->put_message);
			// ft_all_clear(data);
			return (NULL);
		}
		else
			usleep(1000);
	}
	return (NULL);
}

void	philo_check_life(t_philo *philo)
{
	long long	check;

	check = get_timestamp() - philo->check_time;
	if (check >= philo->t_to_die)
	{
		g_life = 0;
		philo_print(philo, 6);
		// break ;
	}
}
