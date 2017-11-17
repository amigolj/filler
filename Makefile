#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 16:43:49 by mkurchin          #+#    #+#              #
#    Updated: 2017/04/19 16:43:50 by mkurchin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler
FL = -Wall -Wextra -Werror
SRC = main.c ft_put_figure.c ft_sv_cord.c ft_struct_crt.c get_next_line.c ft_init_struct.c
SRC_O = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRC_O)
	@make -C libft
	@gcc $(FL) -o $(NAME) $(SRC_O) $(LIBFT)

.c.o:
	@gcc $(FL) -c $< -o $@

clean:
	rm -f $(SRC_O)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
