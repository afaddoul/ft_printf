/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:01:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 14:52:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		realloc_shape(t_shape *node, char *tmp, int len)
{
	free(node->shape);
	node->shape = ft_strdup_len(tmp, len);
	ft_strdel(&tmp);
}
