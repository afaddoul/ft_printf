/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 10:34:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 15:59:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		conv_p(t_shape *node)
{
	char	*tmp;
	char	*tmp_f;
	int		len;
	int		arg_len;

	len = (ft_strlen(node->arg.p) + 2);
	arg_len = len;
	len = (node->field_w.f_w > arg_len) ? node->field_w.f_w : arg_len;
	tmp = ft_strnew(len + 1);
	tmp = ft_memset(tmp, ' ', len);
	tmp_f = node->arg.p;
	node->arg.p = ft_strjoin("0x", node->arg.p);
	free(tmp_f);
	tmp = (node->flg.flg[0] == 1) ? cpy_arg(tmp, node->arg.p, 0) :
		cpy_arg(tmp, node->arg.p, (len - arg_len));
	realloc_shape(node, tmp, len);
}
