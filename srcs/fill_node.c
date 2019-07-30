/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 01:46:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/30 14:39:47 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		init_l_m_and_flg_tab(t_shape *node)
{
	node->flg.flg[0] = 0;
	node->flg.flg[1] = 0;
	node->flg.flg[2] = 0;
	node->flg.flg[3] = 0;
	node->flg.flg[4] = 0;
	node->l_m.l_mod[0] = 0;
	node->l_m.l_mod[1] = 0;
	node->l_m.l_mod[2] = 0;
	node->l_m.l_mod[3] = 0;
	node->l_m.l_mod[4] = 0;
}

void		init_flg_pre_dlr_f_w(t_shape *node)
{
	node->d.dlr_flg = 0;
	node->flg.f_flg = 0;
	node->field_w.f_w_flg = 0;
	node->field_w.f_w = 0;
	node->p.pre_flg = 0;
	node->p.pre = 0;
	node->l_m.l_m_flg = 0;
}

void		init_args(t_shape *node)
{
	node->arg.c = '\0';
	node->arg.s = NULL;
	node->arg.p = NULL;
	node->arg.d = 0;
	node->arg.i = 0;
	node->arg.u = 0;
	node->arg.o = 0;
	node->arg.x = 0;
	node->arg.big_x = 0;
	node->arg.dbl = 0;
	node->arg.l_dbl = 0;
}

t_shape		*fill_node(t_shape *node, t_arg *arg, int index, int flag)
{
	node->conv_flag = flag;
	node->shape = arg->buff;
	init_l_m_and_flg_tab(node);
	init_flg_pre_dlr_f_w(node);
	init_args(node);
	if (flag == 1)
	{
		node->d.dlr_flg = arg->dlr;
		node->d.d_val = arg->dlr_v;
		node->field_w.f_w_flg = arg->f_w_star;
		node->p.pre_flg = arg->pre_star;
		node->index = index;
		node->conv = arg->cv;
		if (conv_finder(node->conv))
			exit(-1);
		node = parse_data(node, arg->buff);
	}
	free(arg);
	return (node);
}
