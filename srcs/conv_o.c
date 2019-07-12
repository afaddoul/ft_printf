/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:04:19 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/12 20:56:26 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		length_specifier(t_shape *node, t_conv_o *o)
{
	if (node->flg.flg[4] && node->arg.o)
	{
		if (node->p.pre >= o->arg_len && node->p.pre >= node->field_w.f_w)
			(o->len)++;
		else if (o->arg_len >= node->p.pre && o->arg_len >= node->field_w.f_w)
			(o->len)++;
	}
	if (node->field_w.f_w >= o->arg_len && node->field_w.f_w >= node->p.pre)
		o->len += node->field_w.f_w;
	else if (node->p.pre >= o->arg_len)
		o->len += node->p.pre;
	else if (o->arg_len > node->p.pre && o->arg_len > node->field_w.f_w)
		o->len += o->arg_len;
}

static char		*create_str_and_fill_struct(t_shape *node, t_conv_o *o)
{
	char		*tmp;
	int			hash;

	hash = node->flg.flg[4] ? 1 : 0;
	tmp = ft_strnew(o->len);
	tmp = ft_memset(tmp, ' ', o->len);
	if (hash)
		hash = (!node->arg.o) ? 0 : 1;
	o->zr = (node->p.pre - o->arg_len > 0) ? node->p.pre - o->arg_len : 0;
	o->sp = (node->field_w.f_w - o->arg_len - o->zr - hash > 0) ?
		(node->field_w.f_w - o->arg_len - o->zr - hash) : 0;
	o->sp = (o->sp > 0) ? o->sp : 0;
	if (((node->p.pre - o->arg_len) == o->zr) && node->flg.flg[4])
		o->len--;
	if (node->p.pre > o->arg_len && node->field_w.f_w > node->p.pre
			&& node->flg.flg[4] && node->arg.o)
		o->sp++;
	return (tmp);
}

static void		put_prefix_and_zero(t_shape *node, t_conv_o *o, char *tmp)
{
	if (!node->flg.flg[0] && node->flg.flg[2] && node->p.pre_flg)
	{
		o->counter = o->sp;
		while (tmp[o->cursor] && o->counter--)
			tmp[(o->cursor)++] = ' ';
	}
	if (node->flg.flg[4] && node->arg.o && (node->p.pre - o->arg_len != o->zr))
		tmp[(o->cursor)++] = '0';
	if (!node->flg.flg[0] && node->flg.flg[2] && !node->p.pre_flg)
	{
		o->counter = o->sp;
		while (tmp[o->cursor] && o->counter--)
			tmp[(o->cursor)++] = '0';
	}
	o->counter = o->zr;
	while ((o->counter)--)
		tmp[(o->cursor)++] = '0';
}

static void		put_sp(t_shape *node, t_conv_o *o, char *tmp)
{
	if (node->flg.flg[0])
	{
		o->counter = o->sp;
		while (tmp[o->cursor] && (o->counter)--)
			tmp[(o->cursor)++] = ' ';
	}
}

void			conv_o(t_shape *node)
{
	t_conv_o	*o;
	char		*tmp;

	o = NULL;
	o = init_struct_o(o);
	cast_unsigned_type_o(node);
	o->oct = ft_itoa_base(node->arg.o, 8, 1);
	o->arg_len = ft_strlen(o->oct);
	if (node->p.pre_flg && !node->p.pre && !node->arg.o && !node->flg.flg[4])
		o->arg_len = 0;
	if (node->flg.flg[0] && node->flg.flg[2])
		node->flg.flg[2] = 0;
	length_specifier(node, o);
	tmp = create_str_and_fill_struct(node, o);
	if (!node->flg.flg[0] && !node->flg.flg[2])
	{
		o->counter = o->sp;
		while (tmp[o->cursor] && o->counter--)
			tmp[(o->cursor)++] = ' ';
	}
	put_prefix_and_zero(node, o, tmp);
	cpy_arg_o(tmp, node, o);
	put_sp(node, o, tmp);
	realloc_shape(node, tmp, o->cursor);
	free(o);
}
