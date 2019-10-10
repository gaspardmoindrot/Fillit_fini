# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 13:13:41 by gmoindro          #+#    #+#              #
#    Updated: 2019/07/09 09:44:49 by rbeaufre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = main.c \
	   ft_open_file.c \
	   ft_comp_grid.c \
	   ft_grid_final.c \
	   ft_put.c \
	   ft_utils.c \
	   ft_bon_tris.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -g3 -fsanitize=address -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME) libft/includes/libft.h.gch
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
