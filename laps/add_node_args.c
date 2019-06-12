/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:56:57 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/09 15:07:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_data				*add_node(t_data *head, char cv)
{
	t_data			*node;

	node = (t_data*)malloc(sizeof(t_data));
	node->conv = cv;
	if (head == NULL)
	{
		node->next = NULL;
		return (node);
	}
	else
	{
		head->next = node;
		node->next = NULL;
	}
	return (node);
}
