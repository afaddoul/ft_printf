/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_dlr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:03:25 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/20 12:35:30 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		parse_arg_dlr(t_tmp_data **tab, va_list *ap, int index)
{
	if (tab[index]->conv == 'c')
		tab[index]->c = va_arg(*ap, int);
	else if (tab[index]->conv == 's')
		tab[index]->s = va_arg(*ap, char*);
	else if (tab[index]->conv == 'p')
		tab[index]->p = va_arg(*ap, void*);
	else if (tab[index]->conv == 'd')
		tab[index]->d = va_arg(*ap, long long);
	else if (tab[index]->conv == 'i')
		tab[index]->i = va_arg(*ap, long long);
	else if (tab[index]->conv == 'u')
		tab[index]->u = va_arg(*ap, unsigned long long);
	else if (tab[index]->conv == 'o')
		tab[index]->o = va_arg(*ap, unsigned long long);
	else if (tab[index]->conv == 'x')
		tab[index]->x = va_arg(*ap, unsigned long long);
	else if (tab[index]->conv == 'X')
		tab[index]->big_x = va_arg(*ap, unsigned long long);
	else if ((tab[index]->conv == 'f') ||
			(tab[index]->conv == 'f' && tab[index]->lm[2]))
		tab[index]->dbl = va_arg(*ap, double);
	else if (tab[index]->conv == 'f' && tab[index]->lm[4])
		tab[index]->l_dbl = va_arg(*ap, long double);
	else if (tab[index]->conv == '%')
		tab[index]->s = ft_strdup("%");
}

t_tmp_data	**fill_sorted_arr(t_tmp_data **tab, va_list *ap)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		parse_arg_dlr(tab, ap, i);
		i++;
	}
	return (tab);
}
