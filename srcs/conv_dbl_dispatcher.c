/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 16:03:48 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <limits.h>
#include <float.h>
#include <limits.h>

char			*dbl_dispatcher(t_shape *node)
{
	t_helper	*dbl;
	t_dbl		f;
	char		*str;
	char		*tmp;
	int			sp_case;

	dbl = NULL;
	f.dbl = node->arg.dbl;
	dbl_init_vars(&dbl);
	if (node->p.pre < 0)
		node->p.pre = 6;
	sp_case = spl_case(f);
	if (sp_case == -1 || sp_case == 0 || sp_case == 1)
	{
		multi_free(7, dbl->mantissa, dbl->pow, dbl->nbr, dbl->ten, dbl->zero,
				dbl->one, dbl);
		return (sp_case_ret(sp_case));
	}
	compute_mantissa(dbl, f);
	compute_exp_radix(dbl, f);
	str = put_radix_and_trim_zeros(dbl);
	multi_free(7, dbl->mantissa, dbl->pow, dbl->nbr, dbl->ten, dbl->zero,
			dbl->one, dbl);
	tmp = str;
	str = ft_chopping(node, str);
	free(tmp);
	return (str);
}
