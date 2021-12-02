/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:12:17 by abridger          #+#    #+#             */
/*   Updated: 2021/12/02 17:46:03 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	ft_philo_clear(t_data *data)
{
	if (data->thinker)
	{
		free(data->thinker);
		data->thinker = NULL;
	}
}

void	ft_all_clear(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		ft_philo_clear(data);
		sem_close(data->forks);
		sem_close(data->put_message);
		sem_close(data->times_meal);
		// sem_close(data->end);
		sem_unlink("/forks");
		sem_unlink("/message");
		sem_unlink("/meal");
		// sem_unlink("/end");
	}
}

static int	put_err_str(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

int	put_error_message(t_data *data, int check)
{
	write(STDERR_FILENO, "Error: ", 7);
	if (check == 1)
		return (put_err_str("The wrong number of arguments!"));
	else if (check == 2)
		return (put_err_str("The wrong argument(s)!"));
	else if (check == 3)
		return (put_err_str("Malloc error!"));
	else if (check == 4)
		return (put_err_str("Failed to create thread!"));
	else if (check == 5)
		return (put_err_str("Failed to join thread!"));
	// else if (check == 6)
	// 	return (put_err_str("Failed to init mutex!"));
	else if (check == 7)
		return (put_err_str("Failed to detach thread!"));
	ft_all_clear(data);
	return (1);
}
