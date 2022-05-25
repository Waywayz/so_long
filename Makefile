# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 19:17:05 by rovillar          #+#    #+#              #
#    Updated: 2022/05/25 18:14:13 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ft_printf/libftprintf.a

PRINTF = libftprintf.a

NAME = so_long

SRC =	main.c init_graphic.c check_map.c make_map.c draw_map.c update.c keyboard.c gameplay.c poss_move.c game_utils.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
 		ft_printf/libft/ft_split.c ft_printf/libft/ft_strjoin.c ft_printf/libft/ft_strlen.c \
		ft_printf/ft_printf.c \

OBJ =	${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C ./ft_printf
	${CC} ${CFLAGS} -L ./mlx -lmlx -O3 -framework OpenGL -framework Appkit $(OBJ) $(FT_PRINTF) -o $(NAME)

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf $(OBJ)
	
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

run:
	./$(NAME) *.ber
	
re: fclean all

.PHONY:	all clean fclean re
