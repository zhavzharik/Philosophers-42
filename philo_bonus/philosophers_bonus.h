/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/29 22:12:34 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				pos;
	int				pid;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				nb_eat;
	long long		check_time;
	long long		prev_time;
	long long		start_time;
	long long		death_time;
	int				life;
	int				odd;
	int				last_odd;
	sem_t			*l_fork;
	sem_t			*r_fork;
	sem_t			*message;
	pthread_t		philo_thread;
	pthread_t		waiter;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_eat;
	int				everyone_ate;
	// int				end;
	long long		start_time;
	sem_t			*forks;
	sem_t			put_message;
	t_philo			*thinker;
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			put_error_message(t_data *data, int check);
int			put_input(t_data *data, char **argv);
long long	get_timestamp(void);
void		philo_process(t_data *data);
void		wait_waiter(t_data *data, int i);
void		philo_eat(t_philo *philo);
void		*philo_routine(void *philosopher);
void		ft_all_clear(t_data *data);
int			ft_semaphore_init(t_data *data);
int			action(t_data *data, char **argv, int id);
void		philo_print(t_philo *philo, int message);
void		*philo_status(void *philosopher);
void		*program_print(t_data *data, int message);
void		check_time(t_philo *philo, int flag);

#endif
