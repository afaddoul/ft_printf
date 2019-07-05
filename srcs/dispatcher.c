/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:43:55 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 18:51:10 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** add if statement each time you finish a conv
*/

int						index_finder(t_shape *node)
{
	int					i;

	i = 0;
	if (node->conv == 'c')
		i = 0;
	else if (node->conv == 's')
		i = 1;
	else if (node->conv == 'p')
		i = 2;
	else if (node->conv == 'i' || node->conv == 'd')
		i = 3;
	else if (node->conv == '%')
		i = 4;
	else if (node->conv == 'u')
		i = 5;
	else if (node->conv == 'o')
		i = 6;
	else if (node->conv == 'x')
		i = 7;
	else if (node->conv == 'X')
		i = 8;
	else if (node->conv == 'f')
		i = 9;
	return (i);
}

t_shape					*checker(t_shape *node, int i)
{
	static t_shape		*(*g_p[6])(t_shape*) = {conv_c, conv_s, conv_p, conv_d,
		conv_percent, conv_u};
	t_shape				*tmp;

	tmp = (g_p[i])(node);
	return (tmp);
}

t_shape					*dispatcher(t_shape *lst)
{
	t_shape				*head;
	int					i;

	i = 1;
	head = lst;
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
			i = index_finder(lst);
			lst = checker(lst, i);
		}
		lst = lst->next;
	}
	return (head);
}
