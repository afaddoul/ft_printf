/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_adr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:44:35 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/12 09:36:11 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_data		**receive_adr(t_shape *lst, va_list *ap,int len)
{
	t_data	**tab;
	t_data	*args;
	int		i;

	i = 0;
	tab = (t_data**)malloc(sizeof(t_data*) * (len + 1));
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
			args = add_node(args, lst->conv);
			args = parse_arg_dlr(args, ap);
			tab[i] = args;
			i++;
		}
		lst = lst->next;
	}
	tab[i] = 0;
	return (tab);
}
