/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:34:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/24 17:03:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <limits.h>
#include <float.h>
#include <limits.h>

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

char			*remove_first_zeros(char **nbr)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	len = ft_strlen(*nbr);
	while ((*nbr)[i])
	{
		if (((*nbr)[i] == '0' && (*nbr)[i + 1] == '.') ||
				((*nbr)[i] >= '1' && (*nbr)[i] <= '9'))
			break ;
		i++;
	}
	str = ft_strnew(len - i);
	len = 0;
	while ((*nbr)[i])
		str[len++] = (*nbr)[i++];
	free(*nbr);
	return (str);
}

char			*trim_zeros(char **nbr)
{
	int			zr;
	int			len;
	char		*str;

	len = ft_strlen(*nbr);
	zr = len - 1;
	while ((*nbr)[zr] == '0')
	{
		zr--;
	}
	if ((*nbr)[zr] == '.')
		zr--;
	str = ft_strnew(zr + 1);
	zr++;
	len = 0;
	while (zr)
	{
		str[len] = (*nbr)[len];
		len++;
		zr--;
	}
	free(*nbr);
	str = remove_first_zeros(&str);
	return (str);
}

static void		init_vars(t_helper **dbl)
{
	*dbl = (t_helper*)malloc(sizeof(t_helper));
	(*dbl)->i = 0;
	(*dbl)->shift = 0;
	(*dbl)->len = 0;
	(*dbl)->radix = 0;
	(*dbl)->zero = ft_strdup("0");
	(*dbl)->one = ft_strdup("1");
	(*dbl)->ten = ft_strdup("10");
	(*dbl)->pow = NULL;
	(*dbl)->nbr = NULL;
	(*dbl)->mantissa = NULL;
	(*dbl)->tmp[0] = NULL;
	(*dbl)->tmp[1] = NULL;
}

void			compute_mantissa(t_helper *dbl, t_dbl f)
{
	dbl->mantissa = extract_mantissa(f.dbl_d.manti);
	dbl->nbr = (f.dbl_d.expo == 0) ? dbl->zero : dbl->one;
	while (dbl->mantissa[dbl->i])
	{
		dbl->tmp[0] = dbl->nbr;
		dbl->nbr = multi_op(dbl->nbr, dbl->ten);
		ft_strdel(&(dbl->tmp[0]));
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

char			*put_radix_and_trim_zeros(t_helper *dbl)
{
	char		*str;

	str = ft_strnew(dbl->len);
	str = ft_memset(str, '0', dbl->len);
	while (dbl->len > -1)
	{
		if (dbl->radix == -1)
		{
			str[dbl->len] = '.';
			dbl->radix--;
			dbl->len--;
		}
		else
		{
			str[dbl->len] = dbl->nbr[dbl->nbr_len];
			dbl->len--;
			dbl->nbr_len--;
			dbl->radix--;
		}
	}
	str = trim_zeros(&str);
	multi_free(6, dbl->mantissa, dbl->pow, dbl->nbr, dbl->ten, dbl->zero, dbl);
	return (str);
}

char			*dbl_dispatcher(t_shape *node)
{
	t_helper	*dbl;
	t_dbl		f;
	char		*str;

	dbl = NULL;
	f.dbl = node->arg.dbl;
	init_vars(&dbl);
	compute_mantissa(dbl, f);
	compute_exp_radix(dbl, f);
	str = put_radix_and_trim_zeros(dbl);
	return (str);
}

int				main(void)
{
	t_dbl 		f;
	char 		*str;
	t_shape 	*node;

	f.dbl = DBL_MAX;
	node = (t_shape*)malloc(sizeof(t_shape));
	node->arg.dbl = f.dbl;
	str  = dbl_dispatcher(node);
	printf("%s\n", str);
	free(str);
	free(node);
	return (0);
}
