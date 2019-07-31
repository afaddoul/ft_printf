/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ldbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 19:28:46 by afaddoul         ###   ########.fr       */
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

	ldbl = NULL;
	f.ldbl = node->arg.l_dbl;
	ldbl_init_vars(&ldbl);
	sp_case = l_spl_case(f);
	if (sp_case == -1 || sp_case == 0 || sp_case == 1)
		return (l_sp_case_ret(sp_case));
	l_compute_mantissa(ldbl, f);
	l_compute_exp_radix(ldbl, f);
	printf("|%s|\n\n\n|%s|\n\n\n|%s|\n", ldbl->mantissa, ldbl->pow, ldbl->nbr);
	exit(0)	;
	str = l_put_radix_and_trim_zeros(ldbl);
	tmp = str;
	str = ft_chopping(node, str);
	free(tmp);
	return (str);
}
