/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:28:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 20:40:32 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		length_specifier(t_shape *node, t_conv_x *x)
{
	if (node->flg.flg[4])
	{
		if (node->p.pre >= x->arg_len && node->p.pre >= node->field_w.f_w)
			x->len += 2;
		else if (x->arg_len >= node->p.pre && x->arg_len >= node->field_w.f_w)
			x->len += 2;
	}
	if (node->field_w.f_w >= x->arg_len && node->field_w.f_w >= node->p.pre)
		x->len += node->field_w.f_w;
	else if (node->p.pre >= x->arg_len)
		x->len += node->p.pre;
	else if (x->arg_len > node->p.pre && x->arg_len > node->field_w.f_w)
		x->len += x->arg_len;
}

static char		*create_str_and_fill_struct(t_shape *node, t_conv_x *x)
{
	char		*tmp;

	tmp = ft_strnew(x->len);
	tmp = ft_memset(tmp, ' ', x->len);
	x->zr = (node->p.pre - x->arg_len > 0) ? node->p.pre - x->arg_len : 0;
	x->sp = node->field_w.f_w - x->arg_len - x->zr;
	if (node->flg.flg[4] && node->arg.x)
		x->sp -= 2;
	x->sp = (x->sp > 0) ? x->sp : 0;
	return (tmp);
}

static void		put_prefix_and_zero(t_shape *node, t_conv_x *x, char *tmp)
{
	if (!node->flg.flg[0] && node->flg.flg[2] && node->p.pre_flg)
	{
		x->counter = x->sp;
		while (tmp[x->cursor] && x->counter--)
			tmp[(x->cursor)++] = ' ';
	}
	if (node->flg.flg[4] && node->arg.x)
	{
		tmp[(x->cursor)++] = '0';
		tmp[(x->cursor)++] = 'x';
	}
	if (!node->flg.flg[0] && node->flg.flg[2] && !node->p.pre_flg)
	{
		x->counter = x->sp;
		while (tmp[x->cursor] && x->counter--)
			tmp[(x->cursor)++] = '0';
	}
	x->counter = x->zr;
	while ((x->counter)--)
		tmp[(x->cursor)++] = '0';
}

static void		put_sp(t_shape *node, t_conv_x *x, char *tmp)
{
	if (node->flg.flg[0])
	{
		x->counter = x->sp;
		while (tmp[x->cursor] && (x->counter)--)
			tmp[(x->cursor)++] = ' ';
	}
}

void			conv_x(t_shape *node)
{
	t_conv_x	*x;
	char		*tmp;

	x = NULL;
	x = init_struct_x(x);
	cast_unsigned_type_x(node);
	x->hex = ft_itoa_base(node->arg.x, 16, 1);
	x->arg_len = ft_strlen(x->hex);
	if (node->p.pre_flg && !node->p.pre && node->arg.x == 0)
		x->arg_len = 0;
	if (node->flg.flg[0] && node->flg.flg[2])
		node->flg.flg[2] = 0;
	length_specifier(node, x);
	tmp = create_str_and_fill_struct(node, x);
	if (!node->flg.flg[0] && !node->flg.flg[2])
	{
		x->counter = x->sp;
		while (tmp[x->cursor] && x->counter--)
			tmp[(x->cursor)++] = ' ';
	}
	put_prefix_and_zero(node, x, tmp);
	cpy_arg_x(tmp, node, x);
	put_sp(node, x, tmp);
	realloc_shape(node, tmp, x->cursor);
	free(x);
}
