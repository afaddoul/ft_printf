/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_init_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 21:31:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/28 23:20:50 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		dbl_init_vars(t_helper **dbl)
{
	if (!(*dbl = (t_helper*)malloc(sizeof(t_helper))))
		return ;
	(*dbl)->i = 0;
	(*dbl)->shift = 0;
	(*dbl)->len = 0;
	(*dbl)->radix = 0;
	(*dbl)->zero = ft_strdup("0");
	(*dbl)->one = ft_strdup("1");
	(*dbl)->ten = ft_strdup("10");
	(*dbl)->pow = NULL;
	(*dbl)->nbr = NULL;
	(*dbl)->mantissa = NULL;
	(*dbl)->tmp[0] = NULL;
	(*dbl)->tmp[1] = NULL;
}
