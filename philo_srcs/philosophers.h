/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/19 16:35:14 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				pos;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	// int				times_eat; //
	int				nb_eat;
	long long		check_time;
	long long		prev_time;
	long long		start_time;
	long long		death_time;
	int				life;
	// int				hungry; //
	int				last_odd;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*message;
	pthread_t		philo_thread;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_eat;
	int				everyone_ate;
	int				end;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	put_message;
	t_philo			*thinker;
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			put_error_message(t_data *data, int check);
int			put_input(t_data *data, char **argv);
long long	get_timestamp(void);
void		start_philo_threads(t_data *data);
void		detach_philo_threads(t_data *data);
void		philo_eat(t_philo *philo);
void		*philo_routine(void *philosopher);
void		ft_all_clear(t_data *data);
int			ft_mutex_init(t_data *data);
int			action(t_data *data, char **argv);
void		philo_print(t_philo *philo, int message);
void		monitor(pthread_t *waiter, t_data *data);
void		*philo_status(void *info);
void		*program_print(t_data *data, int message, int i);
// void		check_philo_life(t_philo *philo);
void		check_time(t_philo *philo, int flag);

#endif
