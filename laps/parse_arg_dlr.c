/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_dlr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:03:25 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/12 09:31:41 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_data		*parse_arg_dlr(t_data *lst, va_list *ap)
{
	if (lst->conv == 'c')
		lst->c = va_arg(*ap, int);
	else if (lst->conv == 's')
		lst->s = va_arg(*ap, char*);
		else if (lst->conv == 'p')
		lst->p = va_arg(*ap, void*);
	else if (lst->conv == 'd')
		lst->d = va_arg(*ap, int);
	else if (lst->conv == 'i')
		lst->i = va_arg(*ap, int);
	else if (lst->conv == 'u')
		lst->u = va_arg(*ap, unsigned int);
	else if (lst->conv == 'o')
		lst->o = va_arg(*ap, unsigned int);
	else if (lst->conv == 'x')
		lst->x = va_arg(*ap, unsigned int);
	else if (lst->conv == 'X')
		lst->big_x = va_arg(*ap, unsigned int);
	else if (lst->conv == 'f')
		lst->f = va_arg(*ap, double);
		return (lst);
}
