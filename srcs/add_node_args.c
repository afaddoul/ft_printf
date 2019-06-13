/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:56:57 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/12 20:32:46 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_tmp_data				*add_node(t_tmp_data *head, char cv, int dlr)
{
	t_tmp_data			*node;

	node = (t_tmp_data*)malloc(sizeof(t_tmp_data));
	node->conv = cv;
	node->dlr = dlr;
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
