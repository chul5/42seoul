# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coh <coh@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 19:12:58 by coh               #+#    #+#              #
#    Updated: 2023/02/14 16:58:17 by coh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	server client

SRCS		=	server.c\
				utils.c\
				client.c

SRCS_BN		=	server_bonus.c\
				client_bonus.c\

OBJS		= $(SRCS:.c=.o)
OBJS_BN		= $(SRCS_BN:.c=.o)

CFLAG		= -Wall -Wextra -Werror
CC			= cc

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BN)
else
	OBJECTS = $(OBJS)
endif

all	:	$(NAME)

.c.o	:
			$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJECTS)

ifneq ($(OBJECTS), $(OBJS))
	$(CC) $(CFLAG) -o client client_bonus.o utils.o
	$(CC) $(CFLAG) -o server server_bonus.o utils.o
else
	$(CC) $(CFLAG) -o client client.o utils.o
	$(CC) $(CFLAG) -o server server.o utils.o
endif

clean	:
		rm -f $(OBJS) $(OBJS_BN)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean
			make all

bonus	:
			make WITH_BONUS=1 all

.PHONY	:	all clean fclean re bonus