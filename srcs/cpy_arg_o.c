/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:19:57 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/08 19:28:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*cpy_arg_o(char *shape, t_shape *node, t_conv_o *o)
{
	int		j;
	int		len;

	j = 0;
	if (!node->arg.o && !node->p.pre && node->p.pre_flg && !node->flg.flg[4])
		return (shape);
	len = ft_strlen(o->oct);
	while (j < len)
		shape[(o->cursor)++] = o->oct[j++];
	free(o->oct);
	return (shape);
}
