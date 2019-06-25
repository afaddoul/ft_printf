/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:01:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/25 10:19:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*realloc_shape(t_shape *node, char *tmp, int len)
{
	free(node->shape);
	node->shape = ft_strdup_len(tmp, len);
	free(tmp);
	return (node);
}
