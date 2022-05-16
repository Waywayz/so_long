# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rovillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 19:17:05 by rovillar          #+#    #+#              #
#    Updated: 2022/05/16 18:39:16 by rovillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ft_printf/libftprintf.a

PRINTF_PATH = ft_printf

PRINTF = libftprintf.a

NAME = so_long

SRC =	main.c init_graphic.c check_map.c make_map.c draw_map.c update.c keyboard.c gameplay.c poss_move.c game_utils.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
 		libft/ft_bzero.c libft/ft_calloc.c libft/ft_memset.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c \
		 libft/ft_strlen.c libft/ft_substr.c \
		ft_printf/ft_printf.c \

OBJ =	${SCRS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./GNL/get_next_line.h so_long.h ./libft/libft.h -I ./mlx/mlx.h

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	${CC} ${CFLAGS} -L ./mlx -lmlx -O3 -framework OpenGL -framework Appkit $(SRC) $(FT_PRINTF) -o $(NAME)

$(PRINTF):
	(cd $(PRINTF_PATH) && $(MAKE))

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -f $(NAME)  $(PRINTF)
	cd $(PRINTF_PATH) && $(MAKE) $@

run:
	./$(NAME) *.ber
	
re: fclean all

.PHONY:	all clean fclean re
