/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ldbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 19:47:19 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <limits.h>
#include <float.h>

char			*ldbl_dispatcher(t_shape *node)
{
	t_helper	*ldbl;
	t_ldbl		f;
	char		*str;
	char		*tmp;
	int			sp_case;

	f.ldbl = node->arg.l_dbl;
	ldbl = ldbl_init_vars();
	sp_case = l_spl_case(f);
	if (sp_case == -1 || sp_case == 0 || sp_case == 1)
	{
		multi_free(7, ldbl->mantissa, ldbl->pow, ldbl->nbr, ldbl->ten,
				ldbl->zero, ldbl->one, ldbl);
		return (l_sp_case_ret(sp_case));
	}
	l_compute_mantissa(ldbl, f);
	l_compute_exp_radix(ldbl, f);
	str = l_put_radix_and_trim_zeros(ldbl);
	tmp = str;
	str = ft_chopping(node, str);
	free(tmp);
	return (str);
}
