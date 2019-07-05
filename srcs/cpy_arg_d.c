/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:09:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 15:47:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char *cpy_arg_d(char *shape, t_shape *node, t_conv_d *d)
{
	int j;
	int len;
	char *dc;

	j = 0;
	if (node->arg.d == 0 && !node->p.pre && node->p.pre_flg)
		return (shape);
	if (node->arg.d < 0)
		node->arg.d *= -1;
	dc = ft_itoa(node->arg.d);
	len = ft_strlen(dc);
	while (j < len)
		shape[(d->cursor)++] = dc[j++];
	free(dc);
	return (shape);
}
