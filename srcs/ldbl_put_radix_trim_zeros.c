/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_put_radix_trim_zeros.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:07:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 11:46:41 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			*l_put_radix_and_trim_zeros(t_helper *ldbl)
{
	char		*str;

	str = ft_strnew(ldbl->len);
	str = ft_memset(str, '0', ldbl->len);
	while (ldbl->len > -1)
	{
		if (ldbl->radix == -1)
		{
			str[ldbl->len] = '.';
			ldbl->radix--;
			ldbl->len--;
		}
		else
		{
			str[ldbl->len] = ldbl->nbr[ldbl->nbr_len];
			ldbl->len--;
			ldbl->nbr_len--;
			ldbl->radix--;
		}
	}
	str = remove_first_zeros(&str);
	multi_free(7, ldbl->mantissa, ldbl->pow, ldbl->nbr, ldbl->ten, ldbl->zero,
			ldbl->one, ldbl);
	return (str);
}
