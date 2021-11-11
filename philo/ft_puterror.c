/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:12:17 by abridger          #+#    #+#             */
/*   Updated: 2021/11/11 15:51:32 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_all_clear(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->thinker)
		{
			free(data->thinker);
			data->thinker = NULL;
		}
		if (data->forks)
		{
			while (i < data->nb_philo)
			{
				pthread_mutex_destroy(&(data->forks[i]));
				i++;
			}
			free(data->forks);
			data->forks = NULL;
		}
		pthread_mutex_destroy(&data->put_message);
	}
}

static void	put_err_str(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
}

int	put_error_message(t_data *data, int check)
{
	write(STDERR_FILENO, "Error: ", 7);
	if (check == 1)
		put_err_str("The wrong number of arguments!");
	else if (check == 2)
		put_err_str("The wrong argument(s)!");
	else if (check == 3)
		put_err_str("Malloc error!");
	else if (check == 4)
		put_err_str("Failed to create thread!");
	else if (check == 5)
		put_err_str("Failed to join thread!");
	else if (check == 6)
		put_err_str("Failed to init mutex!");
	ft_all_clear(data);
	return (1);
}
