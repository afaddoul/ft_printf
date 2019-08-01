/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:05:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 21:19:29 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_shapes_fd(t_shape *lst, int fd)
{
	t_shape *tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->conv == 'c')
			print_conv_c(lst);
		else
			ft_putstr_fd(lst->shape, fd);
		lst = lst->next;
	}
}
