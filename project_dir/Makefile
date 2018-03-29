# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skholodn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:14:27 by skholodn          #+#    #+#              #
#    Updated: 2017/11/30 20:21:34 by skholodn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = lem-in.h

SRCS =      main.c \
			gnl/get_next_line.c \
			parsing_ants_rooms.c \
			arr_free.c \
            validation.c \
            help_func.c \
            pathfinder.c \
            ants_move.c \
            rooms_func.c \
            queue_func.c \
            best_root.c \
            parse_start_end.c \
            path_clear.c

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF)

%.o: %.c $(INCLUDES) 
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

$(LIBFT):
	make -C ./libft/

$(PRINTF):
	make -C ./ft_printf/

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C ft_printf/

fclean: 
	rm -f $(OBJ)
	make fclean -C libft/
	make fclean -C ft_printf/	
	rm -f $(NAME)

re: clean all
