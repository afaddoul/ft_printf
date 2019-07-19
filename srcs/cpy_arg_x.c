/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:52:57 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/18 19:14:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*cpy_arg_x(char *shape, t_shape *node, t_conv_x *x)
{
	int		j;
	int		len;

	j = 0;
	if (node->arg.x == 0 && !node->p.pre && node->p.pre_flg)
		return (shape);
	len = ft_strlen(x->hex);
	while (j < len)
		shape[(x->cursor)++] = x->hex[j++];
	return (shape);
}
