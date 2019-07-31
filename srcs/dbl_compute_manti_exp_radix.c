/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_compute_manti_exp_radix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:04:13 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 11:45:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			*extract_mantissa(unsigned long manti)
{
	char		*bin;
	char		*full_bin;
	int			i;
	int			j;

	full_bin = ft_strnew(52);
	full_bin = ft_memset(full_bin, '0', 52);
	bin = ft_itoa_base(manti, 2, 1);
	i = (ft_strlen(bin) - 1);
	j = 51;
	while (i >= 0)
		full_bin[j--] = bin[i--];
	free(bin);
	return (full_bin);
}

void			compute_mantissa(t_helper *dbl, t_dbl f)
{
	int			check;

	check = 0;
	dbl->mantissa = extract_mantissa(f.dbl_d.manti);
	dbl->nbr = (f.dbl_d.expo == 0) ? ft_strdup(dbl->zero) : ft_strdup(dbl->one);
	while (dbl->mantissa[dbl->i])
	{
		dbl->tmp[0] = dbl->nbr;
		dbl->nbr = multi_op(dbl->nbr, dbl->ten);
		if (check > 0)
			free(dbl->tmp[0]);
		check++;
		if (dbl->mantissa[dbl->i] == '1')
		{
			dbl->tmp[0] = dbl->nbr;
			dbl->tmp[1] = ft_str_power("5", (dbl->i + 1));
			dbl->nbr = add_op(dbl->nbr, dbl->tmp[1]);
			multi_free(2, dbl->tmp[0], dbl->tmp[1]);
			dbl->shift = dbl->i + 1;
		}
		(dbl->i)++;
	}
}

void			compute_exp_radix(t_helper *dbl, t_dbl f)
{
	if (f.dbl_d.expo - 1023 >= 0)
		dbl->pow = ft_str_power("2", (f.dbl_d.expo - 1023));
	else
	{
		dbl->pow = ft_str_power("5", (f.dbl_d.expo - 1023) * (-1));
		dbl->radix = (f.dbl_d.expo - 1023) * -1;
	}
	dbl->radix += 52;
	dbl->tmp[0] = dbl->nbr;
	dbl->nbr = multi_op(dbl->pow, dbl->nbr);
	free(dbl->tmp[0]);
	dbl->nbr_len = ft_strlen(dbl->nbr);
	if (dbl->radix <= dbl->nbr_len)
		dbl->len = dbl->nbr_len + 1;
	else
		dbl->len += dbl->radix;
}
