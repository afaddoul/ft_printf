# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 18:06:13 by afaddoul          #+#    #+#              #
#    Updated: 2019/07/30 23:22:46 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all : $(NAME)

$(NAME) :
	@gcc -Wextra -Wall -Werror -c srcs/*.c libft/*.c -I includes
	@ar rc $(NAME) *.o

clean :
	@rm -f *.o

fclean : clean
	@rm -rf $(NAME)
	@/bin/rm -f srcs/$(NAME)

re : fclean all
