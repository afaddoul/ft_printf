/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_compute_manti_exp_radix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:04:13 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 17:07:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			*extract_l_mantissa(unsigned long manti)
{
	char		*bin;
	char		*full_bin;
	int			i;
	int			j;

	full_bin = ft_strnew(63);
	full_bin = ft_memset(full_bin, '0', 63);
	bin = ft_itoa_base(manti, 2, 1);
	i = (ft_strlen(bin) - 1);
	j = 62;
	while (i >= 0)
		full_bin[j--] = bin[i--];
	free(bin);
	return (full_bin);
}

void			l_compute_mantissa(t_helper *ldbl, t_ldbl f)
{
	ldbl->mantissa = extract_l_mantissa(f.ldbl_d.manti);
	ldbl->nbr = (f.ldbl_d.bit_int == 0) ? ft_strdup(ldbl->zero) :
		ft_strdup(ldbl->one);
	while (ldbl->mantissa[ldbl->i])
	{
		ldbl->tmp[0] = ldbl->nbr;
		ldbl->nbr = multi_op(ldbl->nbr, ldbl->ten);
		free(ldbl->tmp[0]);
		if (ldbl->mantissa[ldbl->i] == '1')
		{
			ldbl->tmp[0] = ldbl->nbr;
			ldbl->tmp[1] = ft_str_power("5", (ldbl->i + 1));
			ldbl->nbr = add_op(ldbl->nbr, ldbl->tmp[1]);
			multi_free(2, ldbl->tmp[0], ldbl->tmp[1]);
			ldbl->shift = ldbl->i + 1;
		}
		(ldbl->i)++;
	}
}

void			l_compute_exp_radix(t_helper *ldbl, t_ldbl f)
{
	if (f.ldbl_d.expo - 16383 >= 0)
		ldbl->pow = ft_str_power("2", (f.ldbl_d.expo - 16383));
	else
	{
		ldbl->pow = ft_str_power("5", (f.ldbl_d.expo - 16383) * (-1));
		ldbl->radix = (f.ldbl_d.expo - 16383) * -1;
	}
	ldbl->radix += 63;
	ldbl->tmp[0] = ldbl->nbr;
	ldbl->nbr = multi_op(ldbl->pow, ldbl->nbr);
	free(ldbl->tmp[0]);
	ldbl->nbr_len = ft_strlen(ldbl->nbr);
	if (ldbl->radix <= ldbl->nbr_len)
		ldbl->len = ldbl->nbr_len + 1;
	else
		ldbl->len += ldbl->radix;
}
