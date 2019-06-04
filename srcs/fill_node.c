/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 01:46:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/04 04:48:00 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*fill_node(t_shape *node, t_arg *arg, int index, int flag)
{
	node->conv_flag = flag;
	node->shape = arg->buff;
	node->field_w.f_w_flg = 0;
	node->p.pre_flg = 0;
	if (flag == 1)
	{
		node->d.dlr_flg = arg->dlr;
		node->d.d_val = arg->dlr_v;
		node->field_w.f_w_flg = arg->f_w_star;
		node->p.pre_flg = arg->pre_star;
		node->index = index;
		node->conv = arg->cv;
		node = parse_data(node, arg->buff);
	}
	free(arg);
	return (node);
}
