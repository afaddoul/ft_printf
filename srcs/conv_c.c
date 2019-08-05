/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:41:34 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 13:24:38 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		conv_c(t_shape *node)
{
	char	*tmp;
	int		len;

	len = 1;
	if ((node->field_w.f_w) >= 1)
		len = node->field_w.f_w;
	tmp = ft_memalloc_protected(sizeof(char) * (len + 1));
	tmp = ft_memset(tmp, ' ', len);
	if (node->flg.flg[0] == 1)
		tmp[0] = node->arg.c;
	else
		tmp[len - 1] = node->arg.c;
	tmp[len] = '\0';
	realloc_shape(node, tmp, len);
	node->cv_len = len;
}
