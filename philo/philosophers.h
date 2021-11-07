/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/07 23:01:43 by abridger         ###   ########.fr       */
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

struct s_data;
typedef struct s_philo
{
	int				pos;
	int				l_fork;
	int				r_fork;
	int				nb_eat;
	long long		check_time;
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_hungry;
	pthread_mutex_t	put_message;
	t_philo			*thinker;	
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			put_error_message(t_data *data, int check);
int			put_input(t_data *data, char **argv);
int			init_thinkers(t_data *data);
long long	get_timestamp(void);
void		start_threads(t_data *data);
void		join_threads(t_data *data);
void		*philo_routine(void *philosopher);
void		philo_eat(t_philo *philo);
void		ft_all_clear(t_data *data);
int			ft_mutex_init(t_data *data);
int			action(t_data *data, char **argv);

#endif