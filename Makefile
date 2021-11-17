# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 22:52:44 by abridger          #+#    #+#              #
#    Updated: 2021/11/17 17:05:17 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo

NAME_B				=	philo_bonus

SRCS_DIR			=	./philo_srcs/

OBJS_DIR			=	./objs/

SRCS_BONUS_DIR		=	./philo_bonus_srcs/

OBJS_BONUS_DIR		=	./objs_bonus/

HEADER				=	$(SRCS_DIR)philosophers.h

HEADER_BONUS		=	$(SRCS_BONUS_DIR)philosophers_bonus.h

SRCS			=	$(SRCS_DIR)	philosophers.c		\
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




SRCS_BONUS			=	$(SRCS_BONUS_DIR)	philosophers_bonus.c	\
											ft_atoi_bonus.c			\
											ft_time_bonus.c



OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

OBJS_BONUS			=	$(addprefix $(OBJS_BONUS_DIR), $(notdir $(SRCS_BONUS:.c=.o)))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

PTFLAG			=	-pthread

RM				=	rm -f

all:	$(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADER) Makefile | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS_DIR)%.o:	$(SRCS_BONUS_DIR)%.c $(HEADER_BONUS) Makefile | $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(PTFLAG) $(OBJS) -o $@

$(NAME_B): $(OBJS_BONUS)
	$(CC) $(PTFLAG) $(OBJS_BONUS) -o $@

bonus:	$(NAME_B)

clean:
		$(RM) -r $(OBJS_DIR) $(OBJS_BONUS_DIR)

fclean: clean
		$(RM) $(NAME) $(NAME_B)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	mkdir $(OBJS_BONUS_DIR)

re:	fclean $(OBJS_DIR) all

.PHONY:	all clean fclean re bonus
