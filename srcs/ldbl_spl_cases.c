/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_spl_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:59:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 16:24:29 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				l_spl_case(t_ldbl f)
{
	if (f.ldbl_d.expo == 32767)
	{
		if (f.ldbl_d.manti)
			return (0);
		if (f.ldbl_d.sign == 0)
			return (1);
		else if (f.ldbl_d.sign == 1)
			return (-1);
	}
	return (2);
}

char			*l_sp_case_ret(int flag)
{
	char		*str;

	str = NULL;
	if (flag == -1)
		str = ft_strdup("inf");
	else if (flag == 0)
		str = ft_strdup("nan");
	else if (flag == 1)
		str = ft_strdup("inf");
	return (str);
}
