/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_cast_conv_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:19:28 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 21:28:11 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_conv_d		*init_struct(t_conv_d *d)
{
	d = ft_memalloc(sizeof(t_conv_d));
	d->zr = 0;
	d->sign = 0;
	d->sp = 0;
	d->len = 0;
	d->cursor = 0;
	d->counter = 0;
	return (d);
}

t_conv_x		*init_struct_x(t_conv_x *x)
{
	x = ft_memalloc(sizeof(t_conv_x));
	x->hex = NULL;
	x->zr = 0;
	x->sign = 0;
	x->sp = 0;
	x->len = 0;
	x->cursor = 0;
	x->counter = 0;
	return (x);
}

t_conv_o		*init_struct_o(t_conv_o *o)
{
	o = ft_memalloc(sizeof(t_conv_o));
	o->oct = NULL;
	o->zr = 0;
	o->sign = 0;
	o->sp = 0;
	o->len = 0;
	o->cursor = 0;
	o->counter = 0;
	return (o);
}

void			cast_type(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.d = (int)node->arg.d;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.d = (short)node->arg.d;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.d = (signed char)node->arg.d;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.d = (long)node->arg.d;
}
