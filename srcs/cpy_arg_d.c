/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:09:04 by afaddoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/05 20:12:52 by afaddoul         ###   ########.fr       */
=======
/*   Updated: 2019/07/05 15:47:06 by afaddoul         ###   ########.fr       */
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
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
<<<<<<< HEAD
	if (node->conv == 'd')
		dc = ft_itoa(node->arg.d);
=======
	dc = ft_itoa(node->arg.d);
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
	len = ft_strlen(dc);
	while (j < len)
		shape[(d->cursor)++] = dc[j++];
	free(dc);
	return (shape);
}
