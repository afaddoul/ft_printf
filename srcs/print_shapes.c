/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:05:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 20:04:27 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_shapes(t_shape *lst)
{
	t_shape *tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->conv == 'c')
			print_conv_c(lst);
		else
		{
			ft_putstr(lst->shape);
		}
		lst = lst->next;
	}
}
