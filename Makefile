# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 18:06:13 by afaddoul          #+#    #+#              #
#    Updated: 2019/08/05 13:49:50 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

FILES = srcs/ft_memalloc_protected.c srcs/add_node_args.c srcs/add_op.c srcs/add_shape.c srcs/cast_unsigned_type.c srcs/check_null_p.c srcs/conv_big_x.c srcs/conv_c.c srcs/conv_d.c srcs/conv_dbl.c srcs/conv_dbl_dispatcher.c srcs/conv_i.c srcs/conv_ldbl.c srcs/conv_ldbl_dispatcher.c srcs/conv_o.c srcs/conv_p.c srcs/conv_percent.c srcs/conv_s.c srcs/conv_u.c srcs/conv_x.c srcs/cpy_arg.c srcs/cpy_arg_big_x.c srcs/cpy_arg_d.c srcs/cpy_arg_o.c srcs/cpy_arg_u.c srcs/cpy_arg_x.c srcs/customize_arg.c srcs/dbl_chopping.c srcs/dbl_compute_manti_exp_radix.c srcs/dbl_init_structs.c srcs/dbl_put_radix_trim_zeros.c srcs/dbl_spl_cases.c srcs/dbl_tools.c srcs/dispatcher.c srcs/dlr_detector.c srcs/f_w_and_pre_spl_case.c srcs/fill_args_node.c srcs/fill_list.c srcs/fill_node.c srcs/free_lst.c srcs/ft_itoa_base.c srcs/ft_join_c_to_str.c srcs/ft_printf.c srcs/ft_strdup_len.c srcs/ft_unsigned_itoa.c srcs/init_and_cast_conv_d.c srcs/ldbl_compute_manti_exp_radix.c srcs/ldbl_init_structs.c srcs/ldbl_put_radix_trim_zeros.c srcs/ldbl_spl_cases.c srcs/merge_sort_algorithm.c srcs/merge_sort_tools.c srcs/multi_op.c srcs/parse_arg.c srcs/parse_arg_dlr.c srcs/parse_data.c srcs/power.c srcs/print_conv_c.c srcs/print_conv_c_fd.c srcs/print_shapes.c srcs/print_shapes_fd.c srcs/realloc_shape.c srcs/rec_d.c srcs/receive_dlr_args.c srcs/ret_counter.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_digit_counter.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strlowcase.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strrev.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_strupcase.c libft/ft_swap.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_unsigned_nb_len.c libft/ft_word_counter.c 
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIBFT)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c 
clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
