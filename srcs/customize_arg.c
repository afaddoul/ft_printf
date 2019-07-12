/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:10:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 20:15:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		customize_arg(t_shape *node)
{
	char	*tmp;

	tmp = ft_strdup_len(node->arg.s, node->p.pre);
	free(node->arg.s);
	node->arg.s = tmp;
}
