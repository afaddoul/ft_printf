/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:01:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 18:02:56 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*realloc_shape(t_shape *node, char *tmp)
{
	int		len;

	len = ft_strlen(tmp);
	free(node->shape);
	node->shape = (char*)malloc(sizeof(char) * len);
	node->shape = tmp;
	return (node);
}
