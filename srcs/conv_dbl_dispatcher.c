/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/30 19:35:51 by afaddoul         ###   ########.fr       */
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
	sp_case = spl_case(f);
	if (sp_case == -1 || sp_case == 0 || sp_case == 1)
		return (sp_case_ret(sp_case));
	compute_mantissa(dbl, f);
	compute_exp_radix(dbl, f);
	str = put_radix_and_trim_zeros(dbl);
	tmp = str;
	str = ft_chopping(node, str);
	free(tmp);
	return (str);
}
