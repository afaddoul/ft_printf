/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:02:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:34:18 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ret_counter(t_shape *lst)
{
	t_shape *head;
	int		ret;

	head = lst;
	ret = 0;
	while (lst)
	{
		if (lst->conv == 'c')
			ret += lst->cv_len;
		else
			ret += ft_strlen(lst->shape);
		lst = lst->next;
	}
	lst = head;
	return (ret);
}
