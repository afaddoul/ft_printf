/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:46:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:20:37 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_conv_c(t_shape *node)
{
	int		i;

	i = 0;
	while (i < node->cv_len)
	{
		ft_putchar(node->shape[i++]);
	}
}
