/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:43:34 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 15:32:40 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape				*first_node(t_shape *lst, t_shape **tmp, int len)
{
	*tmp = lst;
	lst->lst_len = len;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_shape				*add_shape(t_shape *head, int flag, t_arg *arg)
{
	t_shape			*current;
	t_shape			*node;
	static int		index;
	static t_shape	*tmp;

	if (flag == 1)
		index++;
	node = (t_shape*)malloc(sizeof(t_shape));
	node = fill_node(node, arg, index, flag);
	if (head == NULL)
		return (first_node(node, &tmp, index));
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = node;
		node->prev = current;
		node->next = NULL;
	}
	tmp->lst_len = index;
	return (head);
}
