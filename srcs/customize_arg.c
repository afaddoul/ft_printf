/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:10:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 17:21:11 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*customize_arg(t_shape *node)
{
	char *tmp;

	tmp = ft_strdup_len(node->arg.s, node->p.pre);
	free(node->arg.s);
	node->arg.s = tmp;
	return (node);
}
