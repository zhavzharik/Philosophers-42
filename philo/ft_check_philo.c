/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:45:01 by abridger          #+#    #+#             */
/*   Updated: 2021/11/08 21:12:16 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_everyone_ate(t_philo *philo)
{
	int		i;
	t_data	*d;
	int		check;

	i = 0;
	d = philo->data;
	check = 0;
	if (d->nb_times_eat > 0)
	{
		while (i < d->nb_philo)
		{
			if (d->thinker[i].nb_eat >= d->nb_times_eat)
				check++;
			// printf("Поел %d vs Надо %d\t I = % d\t Check = %d\n", d->thinker[i].nb_eat, d->nb_times_eat, i, check);
			if (check == d->nb_philo)
			{
				d->everyone_ate = 1;
				// break ;
			}
			i++;
		}
	}
}
