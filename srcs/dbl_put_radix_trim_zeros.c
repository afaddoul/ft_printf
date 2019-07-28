/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_put_radix_trim_zeros.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:07:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/28 20:58:13 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
	str = remove_first_zeros(&str);
	multi_free(6, dbl->mantissa, dbl->pow, dbl->nbr, dbl->ten, dbl->zero, dbl);
	return (str);
}
