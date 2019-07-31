/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_spl_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:59:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 17:19:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				spl_case(t_dbl f)
{
	if (f.dbl_d.expo == 2047)
	{
		if (f.dbl_d.manti)
			return (0);
		if (f.dbl_d.sign == 0)
			return (1);
		else if (f.dbl_d.sign == 1)
			return (-1);
	}
	return (2);
}

char			*sp_case_ret(int flag)
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
