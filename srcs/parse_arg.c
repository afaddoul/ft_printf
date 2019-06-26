/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:05 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 10:19:46 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*s_and_p_checker(t_shape *lst, va_list *ap)
{
	char *str;

	if (lst->conv == 's')
	{
		str = va_arg(*ap, char *);
		if (str)
			lst->arg.s = ft_strdup(str);
		else
			lst->arg.s = ft_strdup("(null)");
	}
	else if (lst->conv == 'p')
	{
		str = va_arg(*ap, void *);
		if (str)
			lst->arg.p = ft_strdup(str);
		else
			lst->arg.p = ft_strdup("(null)");
	}
	return (lst);
}

t_shape		*arg_filler(t_shape *lst, va_list *ap)
{
	if (lst->conv == 'c')
		lst->arg.c = va_arg(*ap, int);
	else if (lst->conv == 's' || lst->conv == 'p')
		lst = s_and_p_checker(lst, ap);
	else if (lst->conv == 'd')
		lst->arg.d = va_arg(*ap, int);
	else if (lst->conv == 'i')
		lst->arg.i = va_arg(*ap, int);
	else if (lst->conv == 'u')
		lst->arg.u = va_arg(*ap, unsigned int);
	else if (lst->conv == 'o')
		lst->arg.o = va_arg(*ap, unsigned int);
	else if (lst->conv == 'x')
		lst->arg.x = va_arg(*ap, unsigned int);
	else if (lst->conv == 'X')
		lst->arg.big_x = va_arg(*ap, unsigned int);
	else if (lst->conv == 'f')
		lst->arg.f = va_arg(*ap, double);
	return (lst);
}

t_shape		*parse_arg(t_shape *lst, va_list *ap)
{
	t_shape	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->field_w.f_w_flg == -1)
			lst->field_w.f_w = va_arg(*ap, int);
		if (lst->p.pre_flg == -1)
			lst->p.pre = va_arg(*ap, int);
		lst = arg_filler(lst, ap);
		lst = lst->next;
	}
	return (tmp);
}
