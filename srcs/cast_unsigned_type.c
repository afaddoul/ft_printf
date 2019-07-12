/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_unsigned_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:59:22 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 15:51:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			cast_unsigned_type(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.u = (unsigned int)node->arg.u;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.u = (unsigned short)node->arg.u;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.u = (unsigned char)node->arg.u;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.u = (unsigned long)node->arg.u;
}

void			cast_unsigned_type_x(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.x = (unsigned int)node->arg.x;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.x = (unsigned short)node->arg.x;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.x = (unsigned char)node->arg.x;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.x = (unsigned long)node->arg.x;
}

void			cast_unsigned_type_big_x(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.big_x = (unsigned int)node->arg.big_x;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.big_x = (unsigned short)node->arg.big_x;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.big_x = (unsigned char)node->arg.big_x;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.big_x = (unsigned long)node->arg.big_x;
}

void			cast_unsigned_type_o(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.o = (unsigned int)node->arg.o;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.o = (unsigned short)node->arg.o;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.o = (unsigned char)node->arg.o;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.o = (unsigned long)node->arg.o;
}
