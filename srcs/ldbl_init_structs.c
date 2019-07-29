/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_init_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 21:31:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/29 17:59:44 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ldbl_init_vars(t_helper **ldbl)
{
	if (!(*ldbl = (t_helper*)malloc(sizeof(t_helper))))
		return ;
	(*ldbl)->i = 0;
	(*ldbl)->shift = 0;
	(*ldbl)->len = 0;
	(*ldbl)->radix = 0;
	(*ldbl)->zero = ft_strdup("0");
	(*ldbl)->one = ft_strdup("1");
	(*ldbl)->ten = ft_strdup("10");
	(*ldbl)->pow = NULL;
	(*ldbl)->nbr = NULL;
	(*ldbl)->mantissa = NULL;
	(*ldbl)->tmp[0] = NULL;
	(*ldbl)->tmp[1] = NULL;
}
