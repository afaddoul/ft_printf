/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_w_and_pre_spl_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:20:53 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/18 18:15:27 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*special_case(t_shape *node)
{
	if (node->field_w.f_w < 0)
	{
		node->flg.flg[0] = 1;
		node->field_w.f_w *= -1;
	}
	if (node->p.pre < 0)
		node->p.pre = 0;
	return (node);
}
