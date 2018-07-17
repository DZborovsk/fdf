# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 15:44:13 by dzborovk          #+#    #+#              #
#    Updated: 2018/07/17 15:25:24 by dzborovk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all: $(NAME)

$(NAME): 
	gcc main.c minilibx_macos/libmlx.a -lmlx -framework OpenGL -framework Appkit libft/libft.a -o fdf

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f fdf

re: fclean all
