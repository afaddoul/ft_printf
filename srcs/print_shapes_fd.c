/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:05:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/03 12:31:53 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_shapes_fd(t_shape *lst, int fd)
{
	while (lst)
	{
		if (lst->conv == 'c')
			print_conv_c(lst);
		else
			ft_putstr_fd(lst->shape, fd);
		lst = lst->next;
	}
}
