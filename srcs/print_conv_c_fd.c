/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:46:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 21:18:56 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_conv_c_fd(t_shape *node, int fd)
{
	int		i;

	i = 0;
	while (i < node->cv_len)
		ft_putchar_fd(node->shape[i++], fd);
}
