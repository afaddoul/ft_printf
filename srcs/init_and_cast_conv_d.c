/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_cast_conv_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:19:28 by afaddoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/05 17:39:30 by afaddoul         ###   ########.fr       */
=======
/*   Updated: 2019/07/05 15:28:08 by afaddoul         ###   ########.fr       */
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_conv_d		*init_struct(t_conv_d *d)
{
	d = (t_conv_d*)malloc(sizeof(t_conv_d));
	d->zr = 0;
	d->sign = 0;
	d->sp = 0;
	d->len = 0;
	d->cursor = 0;
	d->counter = 0;
	return (d);
}

t_shape			*cast_type(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.d = (int)node->arg.d;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.d = (short)node->arg.d;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.d = (signed char)node->arg.d;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.d = (long)node->arg.d;
	return (node);
}
