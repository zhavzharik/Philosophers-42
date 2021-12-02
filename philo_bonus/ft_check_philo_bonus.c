/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/12/02 20:10:46 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	waiter_reset_lives(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->thinker[i].life = 0;
		i++;
	}
}

static void	check_everyone_ate(t_data *data)
{
	int		check;

	check = 0;
	if (data->nb_times_eat > 0)
	{
		while (data->end == 0)
		{
			sem_wait(data->times_meal);
			check++;
			if (check == data->nb_times_eat)
			{
				data->everyone_ate = 1;
				data->end = 1;
			}
		}
	}
}

static int	check_lives(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	while (i < data->nb_philo)
	{
		check = (int)(data->thinker[i].check_time - data->thinker[i].prev_time);
		// printf("Check = %d\t philo = %d\t", check, data->thinker[i].pos); // delete
		if (check == 0)
			check = get_timestamp() - data->thinker[i].prev_time;
		if (check > data->time_to_die)
		{
			data->thinker[i].life = 0;
			data->thinker[i].death_time = get_timestamp();
			data->end = 1;
			return (i);
		}
		i++;
		// printf("End = %d\n", data->end); // delete
	}
	return (0);
}

void	*philo_status(void *info)
{
	t_data	*data;
	int		i;

	data = (t_data *)info;
	while (data->end == 0)
	{
		check_everyone_ate(data);
		i = check_lives(data);
		if (data->everyone_ate == 1)
		{
			waiter_reset_lives(data);
			return (program_print(data, 6, 1));
		}
		else if (data->end == 1)
		{
			waiter_reset_lives(data);
			return (program_print(data, 5, i));
		}
	}
	return (NULL);
}

// void	*philo_status(void *philosopher)
// {
// 	t_philo	*philo;
// 	int		check;

// 	philo = (t_philo *)philosopher;
// 	while (philo->life == 1)
// 	{
// 		check = (int)(philo->check_time - philo->prev_time);
// 		if (check == 0)
// 			check = get_timestamp() - philo->prev_time;
// 		if (check > philo->t_to_die)
// 		{
// 			philo->death_time = get_timestamp();
// 			philo_print(philo, 5);
// 			philo->life = 0;
// 		}
// 	}
// 	return (NULL);
// }
