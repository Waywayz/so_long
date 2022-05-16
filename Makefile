# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 19:17:05 by rovillar          #+#    #+#              #
#    Updated: 2022/04/06 19:17:07 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ft_printf/libftprintf.a

SRC =	main.c init_graphic.c check_map.c make_map.c draw_map.c update.c keyboard.c gameplay.c poss_move.c game_utils.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
 		libft/ft_bzero.c libft/ft_calloc.c libft/ft_memset.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c \
		 libft/ft_strlen.c libft/ft_substr.c \
		ft_printf/ft_printf.c \


OBJ =	main.o init_graphic.o check_map.o make_map.o map/draw_map.o update.o keyboard.c gameplay.o poss_move.o game_utils.o \
		get_next_line.o get_next_line_utils.o \
 		ft_bzero.o ft_calloc.o ft_memset.o ft_split.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_substr.o \
		ft_printf/ft_printf.o \


HEADER = ./GNL/get_next_line.h so_long.h ./libft/libft.h ./map/map.h -I ./mlx/mlx.h


NAME = so_long


all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra -L ./mlx -lmlx -O3 -framework OpenGL -framework Appkit $(SRC) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $OBJ
	
fclean: clean
	rm -f $(NAME)

run:
	./$(NAME) *.ber
	
re: fclean all

.PHONY:	all clean fclean re
