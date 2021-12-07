/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:12:17 by abridger          #+#    #+#             */
/*   Updated: 2021/12/07 21:50:50 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_kill_process(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->nb_philo)
	{
		kill(data->thinker[i].pid, SIGKILL);
	}
	return (NULL);
}

static void	ft_philo_clear(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	if (data->thinker)
	{
		while (i < data->nb_philo)
		{
			waitpid(-1, &status, 0);
			i++;
		}
		sem_post(data->sem_end);
		free(data->thinker);
		data->thinker = NULL;
	}
}

void	ft_all_clear(t_data *data)
{
	if (data)
	{
		ft_philo_clear(data);
		sem_close(data->forks);
		sem_close(data->put_message);
		sem_close(data->sem_meal);
		sem_close(data->sem_end);
		sem_unlink("/forks");
		sem_unlink("/message");
		sem_unlink("/meal");
		sem_unlink("/end");
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
	else if (check == 7)
		return (put_err_str("Failed to detach thread!"));
	ft_all_clear(data);
	return (1);
}
