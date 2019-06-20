/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlr_detector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:56:13 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:32:28 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		dlr_detector(t_shape *lst)
{
	while (lst)
	{
		if (lst->d.dlr_flg == 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}
