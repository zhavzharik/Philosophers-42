# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 22:52:44 by abridger          #+#    #+#              #
#    Updated: 2021/11/29 18:58:56 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_B			=	philo_bonus

HEADER_B			=	philosophers_bonus.h

SRCS_B			=	philosophers_bonus.c		\
					ft_atoi_bonus.c				\
					ft_puterror_bonus.c			\
					ft_init_data_bonus.c		\
					ft_strlen_bonus.c			\
					ft_time_bonus.c				\
					ft_process_bonus.c			\
					ft_action_bonus.c			\
					ft_sem_open_bonus.c			\
					ft_philo_print_bonus.c		\
					ft_check_philo_bonus.c		\
					ft_eat_bonus.c

OBJS_B			=	$(SRCS_B:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

PTFLAG			=	-pthread

RM				=	rm -rf

bonus:	$(NAME_B)

%.o: %.c $(HEADER_B) Makefile
	$(CC) $(CFLAGS) $(PTFLAG) -c $< -o $@

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(PTFLAG) $(OBJS_B) -o $@

clean:
		$(RM) $(OBJS_B)

fclean: clean
		$(RM) $(NAME_B)

re:	fclean bonus

.PHONY:	clean fclean re bonus
