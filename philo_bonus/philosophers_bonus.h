/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:30:40 by abridger          #+#    #+#             */
/*   Updated: 2021/12/10 20:37:09 by abridger         ###   ########.fr       */
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
	sem_t			*sem_meal;
	sem_t			*sem_end;
	t_philo			*thinker;
	int				end;
	int				everyone_ate;
}					t_data;

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			put_error_message(t_data *data, int check);
int			put_input(t_data *data, char **argv);
long long	get_timestamp(void);
void		philo_process(t_data *data);
void		philo_routine(t_philo *philo);
void		monitor(pthread_t waiter_end, pthread_t waiter_meal, t_data *data);
void		philo_eat(t_philo *philo);
void		ft_all_clear(t_data *data);
int			ft_semaphore_init(t_data *data);
int			action(t_data *data, char **argv);
void		philo_print(t_philo *philo, int message);
void		*philo_status(void *info);
void		program_print(t_data *data);
void		check_time(t_philo *philo, int flag);
void		*game_end(void *info);
void		*check_everyone_ate(void *info);
void		*ft_kill_process(t_data *data);
void		philo_print_death(t_philo *philo);

#endif
