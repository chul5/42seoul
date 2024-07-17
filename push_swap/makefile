# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coh <coh@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 19:19:14 by coh               #+#    #+#              #
#    Updated: 2023/03/02 13:05:41 by coh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	cmp_location.c\
				deallo.c\
				deque.c\
				ft_atoi.c\
				get_loc_a.c\
				greedy.c\
				input.c\
				instruction_p.c\
				instruction_r.c\
				instruction_rr.c\
				instruction_s.c\
				main.c\
				q_sort.c\
				sort_ascending.c\
				start_ps_sw.c\
				utils.c\
				sort.c\

OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

all			:	$(NAME)

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o push_swap

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

.PHONY		:	all clean fclean re