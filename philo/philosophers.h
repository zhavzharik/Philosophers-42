/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/06 20:08:39 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

struct s_data;

typedef struct s_philo
{
	int				pos;
	int				l_fork;
	int				r_fork;
	int				nb_eat;
	int				check_time;
	struct s_data	*data;
	pthread_t		philo_thread;
}					t_philo;
typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_eat;
	int				somebody_dead;
	long long		start_time;
	pthread_mutex_t	forks[300];
	pthread_mutex_t	whether_hungry;
	pthread_mutex_t	put_message;
	t_philo			thinker[300];	
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
void		put_error_message(int check);
void		put_input(t_data *data, char **argv);
void		init_thinkers(t_data *data);
long long	get_timestamp(void);
void		start_threads(t_data *data);
void		join_threads(t_data *data);
void		*routine(void *philo);

#endif