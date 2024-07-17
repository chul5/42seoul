# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coh <coh@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 22:02:27 by coh               #+#    #+#              #
#    Updated: 2023/01/26 16:29:33 by coh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	so_long

SRCS 	=	so_long_main.c\
			so_long_init.c\
			so_long_msg.c\
			so_long_check.c\
			so_long_utils.c\
			so_long_press.c\
			so_long_hook.c\
			queue.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\

OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o so_long

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

.PHONY		:	all clean fclean re
