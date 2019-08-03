/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_dlr_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:13:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/02 18:21:47 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		arg_filler(t_shape *lst, t_tmp_data **tab, int index)
{
	if (tab[index]->conv == 'c')
		lst->arg.c = tab[index]->c;
	else if (tab[index]->conv == 's')
		lst->arg.s = tab[index]->s;
	else if (tab[index]->conv == 'p')
		lst->arg.p = tab[index]->p;
	else if (tab[index]->conv == 'd')
		lst->arg.d = tab[index]->d;
	else if (tab[index]->conv == 'u')
		lst->arg.u = tab[index]->u;
	else if (tab[index]->conv == 'o')
		lst->arg.o = tab[index]->o;
	else if (tab[index]->conv == 'x')
		lst->arg.x = tab[index]->x;
	else if (tab[index]->conv == 'X')
		lst->arg.big_x = tab[index]->big_x;
	else if (tab[index]->conv == 'f' || (tab[index]->conv == 'f' &&
				tab[index]->lm[2]))
		lst->arg.dbl = tab[index]->dbl;
	else if (tab[index]->conv == 'f' && tab[index]->lm[4])
		lst->arg.l_dbl = tab[index]->l_dbl;
	else if (lst->conv == '%')
		lst->arg.s = ft_strdup("%");
}

void			receive_dlr_args(t_shape *lst, t_tmp_data **tab)
{
	int			i;

	i = 0;
	while (lst)
	{
		if (lst->conv_flag == 1)
			arg_filler(lst, tab, (lst->d.d_val - 1));
		lst = lst->next;
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
