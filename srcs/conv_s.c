/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:31:56 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/04 17:00:14 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*conv_s(t_shape *node)
{
	char	*tmp;
	int		len;
	int		arg_len;

	arg_len = ft_strlen(node->arg.s);
	len = arg_len;
	if ((node->p.pre < arg_len) &&
			(node->p.pre_flg == 1 || node->p.pre_flg == -1))
	{
		arg_len = node->p.pre;
		node = customize_arg(node);
	}
	len = (node->field_w.f_w > arg_len) ? node->field_w.f_w : arg_len;
	tmp = ft_strnew(len);
	tmp = ft_memset(tmp, ' ', len);
	tmp = (node->flg.flg[0] == 1) ? cpy_arg(tmp, node->arg.s, 0) :
		cpy_arg(tmp, node->arg.s, (len - arg_len));
	node = realloc_shape(node, tmp, len);
	return (node);
}
