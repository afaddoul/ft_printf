/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:11:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/09 15:08:22 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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
 **0: not found | 1: found0: not found | 1: found
 */
typedef struct				s_dlr
{
	int						d_val;
	int						dlr_flg;
}							t_dlr;

typedef	struct				s_flg
{
	char					flg[5];
	int						f_flg;
}							t_flg;
/*
 ** 0:'-'|1:'+'|2:'0'|3:' '|4:'#' --->'X'
 */
typedef	struct				s_field_width
{
	int						f_w;
	int						f_w_flg;
}							t_field_width;
/*
 ** -1 for * | 0 not found | 1 field width
 */
typedef	struct				s_pre
{
	int						pre;
	int						pre_flg;
}							t_pre;
/*
 ** -1 for * | 0 not found | 1 .pre
 */
typedef struct				s_len_mod
{
	char					l_mod[2];
	int						l_m_flg;
}							t_len_mod;

typedef	struct				s_data
{
	char					conv;
	int						c;
	char					*s;
	void					*p;
	int						d;
	int						i;
	unsigned int			u;
	unsigned int			o;
	unsigned int			x;
	unsigned int			big_x;
	double					f;
	struct s_data			*next;
}							t_data;

typedef	struct				s_shape
{
	char					conv;
	int						conv_flag;
	struct s_dlr			d;
	struct s_flg			flg;
	struct s_field_width	field_w;
	struct s_pre			p;
	struct s_len_mod		l_m;
	int						index;
	char					*shape;
	struct s_data			arg;
	int						lst_len;
	struct s_shape			*next;
	struct s_shape			*prev;
}							t_shape;

int							ft_printf(const char *format, ...);
char						*ft_joinchar(char const *s1, char c);
t_shape						*add_shape(t_shape *head, int flag, t_arg *arg);
t_shape						*fill_node(t_shape *node, t_arg *arg,
		int index, int flag);
t_shape						*fill_list(t_shape *head, char *str);
int							conv_finder(char c);
t_shape						*parse_arg(t_shape *lst, va_list *ap);
t_arg						*rec_d(char *str, t_arg *arg, int start, int end);
t_shape						*swap_dlr(t_shape *lst);
t_shape						*parse_data(t_shape *node, char *str);
t_data						**receive_adr(t_shape *lst, va_list *ap,int len);
t_data						*add_node(t_data *head, char cv);
t_data						*parse_arg_dlr(t_data *lst, va_list *ap);

#endif
