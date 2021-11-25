# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 22:52:44 by abridger          #+#    #+#              #
#    Updated: 2021/11/25 16:11:43 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

HEADER			=	philosophers.h

SRCS			=	philosophers.c		\
					ft_atoi.c			\
					ft_puterror.c		\
					ft_init_data.c		\
					ft_strlen.c			\
					ft_time.c			\
					ft_threads.c		\
					ft_action.c			\
					ft_mutex.c			\
					ft_philo_print.c	\
					ft_check_philo.c	\
					ft_eat.c



OBJS			=	$(SRCS:.c=.o)


CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

PTFLAG			=	-pthread

RM				=	rm -rf

all:	$(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(PTFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PTFLAG) $(OBJS) -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
