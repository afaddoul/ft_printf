/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:45:28 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 16:00:40 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			length_specifier(t_shape *node, t_conv_d *d)
{
	d->len = 0;
	if (node->field_w.f_w >= d->arg_len && node->field_w.f_w >= node->p.pre)
		d->len += node->field_w.f_w;
	else if (node->p.pre >= d->arg_len)
		d->len += node->p.pre;
	else
		d->len += d->arg_len;
}

static char			*create_str_and_fill_struct(t_shape *node, t_conv_d *d)
{
	char		*tmp;

	tmp = ft_strnew(d->len);
	tmp = ft_memset(tmp, ' ', d->len);
	d->zr = (node->p.pre - d->arg_len > 0) ? node->p.pre - d->arg_len : 0;
	d->sp = node->field_w.f_w - d->arg_len - d->zr;
	d->sp = (d->sp > 0) ? d->sp : 0;
	return (tmp);
}

static void			put_sign_and_zero(t_shape *node, t_conv_d *d, char *tmp)
{
	if (!node->flg.flg[0] && node->flg.flg[2] && node->p.pre_flg)
	{
		d->counter = d->sp;
		while (tmp[d->cursor] && d->counter--)
			tmp[(d->cursor)++] = ' ';
	}
	if (!node->flg.flg[0] && node->flg.flg[2] && !node->p.pre_flg)
	{
		d->counter = d->sp;
		while (tmp[d->cursor] && d->counter--)
			tmp[d->cursor++] = '0';
	}
	d->counter = d->zr;
	while ((d->counter)--)
		tmp[(d->cursor)++] = '0';
}

static void			put_sp(t_shape *node, t_conv_d *d, char *tmp)
{
	if (node->flg.flg[0])
	{
		d->counter = d->sp;
		while (tmp[d->cursor] && d->counter--)
			tmp[(d->cursor)++] = ' ';
	}
}

void				conv_u(t_shape *node)
{
	t_conv_d		*d;
	char			*tmp;

	d = NULL;
	d = init_struct(d);
	cast_unsigned_type(node);
	d->arg_len = ft_unsigned_nb_len(node->arg.u);
	if (node->p.pre_flg && !node->p.pre && node->arg.u == 0)
		d->arg_len = 0;
	length_specifier(node, d);
	tmp = create_str_and_fill_struct(node, d);
	if (!node->flg.flg[0] && !node->flg.flg[2])
	{
		d->counter = d->sp;
		while (tmp[d->cursor] && d->counter--)
			tmp[(d->cursor)++] = ' ';
	}
	put_sign_and_zero(node, d, tmp);
	cpy_arg_u(tmp, node, d);
	put_sp(node, d, tmp);
	realloc_shape(node, tmp, d->cursor);
	free(d);
}
