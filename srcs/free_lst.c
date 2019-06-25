/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:59:55 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/22 15:48:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	free_lst(t_shape *lst)
{
	while (lst)
	{
		if (lst->conv_flag == 0)
		{
			free(lst->shape);
			free(lst);
		}
		else
		{
			free(lst->shape);
			if (!(lst->arg.s))
				free(lst->arg.s);
			if (!(lst->arg.p))
				free(lst->arg.p);
			free(lst);
		}
		lst = lst->next;
	}
}
