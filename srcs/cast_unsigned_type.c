/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:59:22 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 20:05:30 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape			*cast_unsigned_type(t_shape *node)
{
	if (node->l_m.l_m_flg == 0)
		node->arg.u = (unsigned int)node->arg.u;
	else if (node->l_m.l_mod[0] == 1)
		node->arg.u = (unsigned short)node->arg.u;
	else if (node->l_m.l_mod[1] == 1)
		node->arg.u = (unsigned char)node->arg.u;
	else if (node->l_m.l_mod[2] == 1)
		node->arg.u = (unsigned long)node->arg.u;
	return (node);
}
