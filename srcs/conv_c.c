/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:41:34 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:23:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*conv_c(t_shape *node)
{
	char	*tmp;
	int		len;
	int		min;
	int		i;

	i = 0;
	len = 1;
	min = 0;
	if ((node->field_w.f_w) >= 1)
		len = node->field_w.f_w;
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	tmp = ft_memset(tmp, ' ', len);
	if (node->flg.flg[0] == 1)
		tmp[0] = node->arg.c;
	else
		tmp[len - 1] = node->arg.c;
	tmp[len] = '\0';
	node = realloc_shape(node, tmp);
	node->cv_len = len;
	return (node);
}
