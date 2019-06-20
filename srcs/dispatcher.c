/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:43:55 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:35:03 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*(*g_p[1])(t_shape*) = {conv_c};

/*
** add if statement each time you finish a conv
*/

int			index_finder(t_shape *node)
{
	int		i;

	if (node->conv == 'c')
		i = 0;
	return (0);
}

t_shape		*dispatcher(t_shape *node, int i)
{
	t_shape	*tmp;

	tmp = (g_p[i])(node);
	return (tmp);
}

t_shape		*checker(t_shape *lst)
{
	t_shape	*head;
	int		i;

	i = 1;
	head = lst;
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
			i = index_finder(lst);
			lst = dispatcher(lst, i);
		}
		lst = lst->next;
	}
	return (head);
}
