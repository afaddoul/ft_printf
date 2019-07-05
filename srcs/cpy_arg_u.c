/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:09:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 20:12:53 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char *cpy_arg_u(char *shape, t_shape *node, t_conv_d *d)
{
	int j;
	int len;
	char *dc;

	j = 0;
	if (node->arg.u == 0 && !node->p.pre && node->p.pre_flg)
	return (shape);
		dc = ft_unsigned_itoa(node->arg.u);
	len = ft_strlen(dc);
	while (j < len)
		shape[(d->cursor)++] = dc[j++];
	free(dc);
	return (shape);
}
