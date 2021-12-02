/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/12/02 22:39:46 by abridger         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_data	t_data;

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
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_eat;
	long long		start_time;
	sem_t			*forks;
	sem_t			*put_message;
	sem_t			*times_meal;
	sem_t			*game_end;
	t_philo			*thinker;
	int				end;
	int				everyone_ate;
	pthread_t		waiter;
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			put_error_message(t_data *data, int check);
int			put_input(t_data *data, char **argv);
long long	get_timestamp(void);
void		philo_process(t_data *data);
void		philo_routine(t_philo *philo);
void		monitor_create(t_data *data);
// void		monitor_join(t_data *data);
void		philo_eat(t_philo *philo);
void		ft_all_clear(t_data *data);
int			ft_semaphore_init(t_data *data);
int			action(t_data *data, char **argv);
void		philo_print(t_philo *philo, int message);
void		*philo_status(void *info);
void		*program_print(t_data *data, int message, int i);
void		check_time(t_philo *philo, int flag);
void		*game_end(void *info);
void		monitor_detach(t_data *data);

#endif
