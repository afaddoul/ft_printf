/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:43:55 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/28 21:23:49 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void					index_finder(t_shape *node, int *i)
{
	if (node->conv == 'c')
		*i = 0;
	else if (node->conv == 's')
		*i = 1;
	else if (node->conv == 'p')
		*i = 2;
	else if (node->conv == 'i' || node->conv == 'd')
		*i = 3;
	else if (node->conv == '%')
		*i = 4;
	else if (node->conv == 'u')
		*i = 5;
	else if (node->conv == 'x')
		*i = 6;
	else if (node->conv == 'X')
		*i = 7;
	else if (node->conv == 'o')
		*i = 8;
	else if (node->conv == 'f' || (node->conv == 'f' && node->l_m.l_mod[2]))
		*i = 9;
	else if (node->conv == 'f' && node->l_m.l_mod[4])
		*i = 10;
}

void					checker(t_shape *node, int i)
{
	static void			(*fct_p_arr[9])(t_shape*) = {conv_c, conv_s, conv_p,
		conv_d, conv_percent, conv_u, conv_x, conv_big_x, conv_o};

	(fct_p_arr[i])(node);
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
			index_finder(lst, &i);
			checker(lst, i);
		}
		lst = lst->next;
	}
	return (head);
}
