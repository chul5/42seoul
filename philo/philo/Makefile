# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coh <coh@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:48:26 by coh               #+#    #+#              #
#    Updated: 2023/03/31 04:00:13 by coh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc

CFLAG	=	-Wall -Werror -Wextra

SRCS	=	init.c\
			main.c\
			philo_eat.c\
			philo_start.c\
			time.c\
			utils.c\
			mutex.c

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $@ $^

%.o		:	%.c
			$(CC) $(CFLAG) -c $< -o $@

clean	:	
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean re