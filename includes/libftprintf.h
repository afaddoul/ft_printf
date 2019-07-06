/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:11:42 by afaddoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/05 20:16:19 by afaddoul         ###   ########.fr       */
=======
/*   Updated: 2019/07/05 15:51:29 by afaddoul         ###   ########.fr       */
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
**-----------------------*
**sorting_tmp_struct
**-----------------------*
*/
typedef	struct				s_tmp_data
{
	char					conv;
	int						dlr;
	int						c;
	char					*s;
	void					*p;
	long int				d;
	long int				i;
	unsigned long int		u;
	unsigned long int		o;
	unsigned long int		x;
	unsigned long int		big_x;
	long double				f;
	struct s_tmp_data		*next;
}							t_tmp_data;

/*
**-----------------------*
**Merge sort struct
**-----------------------*
*/

typedef struct				s_const
{
	int						m;
	int						r;
	int						l;
	int						n1;
	int						n2;
}							t_const;

typedef struct				s_points
{
	t_tmp_data				**left;
	t_tmp_data				**right;
}							t_points;

/*
**-----------------------*
**parsing_struct
**-----------------------*
*/

typedef struct				s_arg
{
	char					*buff;
	int						dlr;
	int						dlr_v;
	int						f_w_star;
	int						pre_star;
	char					cv;
}							t_arg;

/*
**-----------------------*
**dollar struct
** 0: not found | 1: found
**-----------------------*
*/

typedef struct				s_dlr
{
	int						d_val;
	int						dlr_flg;
}							t_dlr;

/*
**-----------------------*
** flg_type_by_index
**<|~|0|->'-'|1|->'+'|2|->'0'|3|->' '|4|->'#'|>~\**
**-----------------------*
*/

typedef	struct				s_flg
{
	char					flg[5];
	int						f_flg;
}							t_flg;

typedef	struct				s_field_width
{
	int						f_w;
	int						f_w_flg;
}							t_field_width;

/*
**-----------------------*
**precision struct
** -1 for * | 0 not found | 1 field width
**-----------------------*
*/

typedef	struct				s_pre
{
	int						pre;
	int						pre_flg;
}							t_pre;

/*
**-----------------------*
**length_modifier_index_by_type
**<|~|0|->'h'|1|->'hh'|2|->'l'|3|->'ll'|4|->'L'|>~\**
**-----------------------*
*/

typedef struct				s_len_mod
{
	int						l_mod[5];
	int						l_m_flg;
}							t_len_mod;

/*
**-----------------------*
**args_structer
**-----------------------*
*/

typedef	struct				s_data
{
	int						c;
	char					*s;
	void					*p;
	long long				d;
	long long				i;
	unsigned long long		u;
	unsigned long long		o;
	unsigned long long		x;
	unsigned long long		big_x;
	long double				f;
}							t_data;

/*
**-----------------------*
**node_structer
**-----------------------*
*/

typedef	struct				s_shape
{
	char					conv;
	int						conv_flag;
	struct s_data			arg;
	struct s_dlr			d;
	struct s_flg			flg;
	struct s_field_width	field_w;
	struct s_pre			p;
	struct s_len_mod		l_m;
	char					*shape;
	int						lst_len;
	int						cv_len;
	int						index;
	struct s_shape			*next;
	struct s_shape			*prev;
}							t_shape;

/*
**-----------------------*
**conv_d_structer
**-----------------------*
*/

typedef	struct				s_conv_d
{
	int						arg_len;
	int						len;
	int						sign;
	int						zr;
	int						sp;
	int						cursor;
	int						counter;
}							t_conv_d;

/*
**-----------------------*
**prototypes
**-----------------------*
*/

int							ft_printf(const char *format, ...);
char						*ft_joinchar(char *s1, char c);
t_shape						*add_shape(t_shape *head, int flag, t_arg *arg);
t_shape						*fill_node(t_shape *node, t_arg *arg,
		int index, int flag);
t_shape						*fill_list(t_shape *head, char *str);
int							conv_finder(char c);
t_shape						*parse_arg(t_shape *lst, va_list *ap);
t_arg						*rec_d(char *str, t_arg *arg, int start, int end);
t_shape						*swap_dlr(t_shape *lst);
t_shape						*parse_data(t_shape *node, char *str);
t_data						**receive_adr(t_shape *lst, va_list *ap, int len);
t_tmp_data					*add_node(t_tmp_data *head, char cv, int dlr);
t_tmp_data					**cp_data(t_shape *lst, int len);
void						cp_data_array_right(t_tmp_data **arr,
		t_points *arrs, t_const *optim, int *i);
void						cp_data_array_left(t_tmp_data **arr,
		t_points *arrs, t_const *optim, int *i);
void						merge_arrays(t_tmp_data **arr, t_points *arrs,
		t_const *optim, int *i);
void						multi_free(int count, ...);
void						init_idx(int l, int *i);
void						merge(t_tmp_data **arr, int l, int m, int r);
void						merge_sort(t_tmp_data **arr, int l, int r);
t_tmp_data					**fill_sorted_arr(t_tmp_data **tab, va_list *ap);
t_tmp_data					**parse_arg_dlr(t_tmp_data **tab, va_list *ap,
		int index);
void						receive_dlr_args(t_shape *lst, t_tmp_data **tab);
int							dlr_detector(t_shape *lst);
t_shape						*realloc_shape(t_shape *node, char *tmp, int len);
t_shape						*checker(t_shape *node, int i);
t_shape						*dispatcher(t_shape *lst);
int							ret_counter(t_shape *lst);
void						print_shapes(t_shape *lst);
void						free_lst(t_shape *lst);
char						*ft_strdup_len(char *s1, int len);
char						*ft_itoa_base(unsigned long long nbr, int base,
		int cse);
int							recursion(unsigned long nbr, char *str,
		int base, int cse);

t_shape						*s_checker(t_shape *lst, va_list *ap);
t_shape						*p_checker(t_shape *lst, va_list *ap);

<<<<<<< HEAD
t_shape						*special_case(t_shape *node);
=======
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
/*
**-----------------------*
**conv_c
**-----------------------*
*/

t_shape						*conv_c(t_shape *node);
void						print_conv_c(t_shape *node);
int							conv_c_len(t_shape *node);

/*
**-----------------------*
<<<<<<< HEAD
**conv_s
=======
**conv_c
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
**-----------------------*
*/

t_shape						*conv_s(t_shape *node);
t_shape						*customize_arg(t_shape *node);
char						*cpy_arg(char *dst, char *src, int i);

/*
**-----------------------*
**conv_p
**-----------------------*
*/

t_shape						*conv_p(t_shape *node);
int							check_null_p(t_shape *node);

/*
**-----------------------*
**conv_d
**-----------------------*
*/
t_shape						*conv_d(t_shape *node);
char						*cpy_arg_d(char *shape, t_shape *node,
		t_conv_d *d);
<<<<<<< HEAD
t_conv_d					*init_struct(t_conv_d *d);
t_shape						*cast_type(t_shape *node);
=======
void						put_sign(t_shape *node, t_conv_d *d, char *tmp);
void						length_specifier(t_shape *node, t_conv_d *d);
char						*create_str_and_fill_struct(t_shape *node,
		t_conv_d *d);
t_conv_d					*init_struct(t_conv_d *d);
t_shape						*cast_type(t_shape *node);
void						put_sign_and_zero(t_shape *node, t_conv_d *d,
		char *tmp);
void						put_sp(t_shape *node, t_conv_d *d, char *tmp);
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
/*
**-----------------------*
**conv_i
**-----------------------*
*/
t_shape						*conv_i(t_shape *node);
/*
**-----------------------*
<<<<<<< HEAD
**conv_percent
=======
**conv_i
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
**-----------------------*
*/
t_shape						*conv_percent(t_shape *node);

<<<<<<< HEAD
/*
**-----------------------*
**conv_u
**-----------------------*
*/

t_shape						*cast_unsigned_type(t_shape *node);
t_shape						*conv_u(t_shape *node);
char						*ft_unsigned_itoa(unsigned long long n);
int							ft_unsigned_nb_len(unsigned long long n);
char						*cpy_arg_u(char *shape, t_shape *node,
		t_conv_d *d);

=======
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
#endif
