/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:40:15 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 17:58:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			conv_ldbl(t_shape *node)
{
	char		*tmp;
	t_ldbl		*uni;
	t_conv_dbl	*ldbl;

	uni = ft_memalloc(sizeof(t_ldbl));
	ldbl = ft_memalloc(sizeof(t_conv_dbl));
	uni->ldbl = node->arg.l_dbl;
	ldbl->sign = uni->ldbl_d.sign;
	ldbl->i = 0;
	ldbl->cursor = 0;
	ldbl->arg = ldbl_dispatcher(node);
	ldbl->arg_len = ft_strlen(ldbl->arg);
	ldbl->len = ldbl->arg_len;
	if (node->flg.flg[3] && node->flg.flg[1])
		node->flg.flg[3] = 0;
	if (node->flg.flg[2] && node->flg.flg[0])
		node->flg.flg[2] = 0;
	if (node->flg.flg[0] && node->flg.flg[1])
		node->flg.flg[0] = 0;
	if (node->field_w.f_w >= ldbl->arg_len)
		ldbl->len = node->field_w.f_w;
	else if (ldbl->arg_len > node->field_w.f_w)
		ldbl->len = ldbl->arg_len;
	if ((ldbl->len <= ldbl->arg_len) &&
			(node->flg.flg[1] || node->flg.flg[3] || ldbl->sign))
		ldbl->len++;
	tmp = ft_strnew(ldbl->len);
	tmp = ft_memset(tmp, ' ', ldbl->len);
	if (node->flg.flg[0])
	{
		if (ldbl->sign == 1)
			tmp[ldbl->cursor++] = '-';
		if (node->flg.flg[1] || node->flg.flg[3])
		{
			if (node->flg.flg[1])
				tmp[(ldbl->cursor)++] = '+';
			else
				ldbl->cursor++;
		}
		while (tmp[(ldbl->cursor)] && ldbl->arg_len--)
			tmp[(ldbl->cursor)++] = ldbl->arg[(ldbl->i)++];
	}
	else
	{
		if (!node->flg.flg[2])
		{
			ldbl->cursor = ldbl->len - ldbl->arg_len;
			if (ldbl->sign || node->flg.flg[1] || node->flg.flg[3])
				(ldbl->cursor)--;
			if (ldbl->sign == 1)
				tmp[ldbl->cursor++] = '-';
			if ((node->flg.flg[1] || node->flg.flg[3]) && !ldbl->sign)
			{
				if (node->flg.flg[1])
					tmp[(ldbl->cursor)++] = '+';
				else
					ldbl->cursor++;
			}
			while (tmp[(ldbl->cursor)])
				tmp[(ldbl->cursor)++] = ldbl->arg[(ldbl->i)++];
		}
		else
		{
			if (ldbl->sign == 1)
				tmp[ldbl->cursor++] = '-';
			if (node->flg.flg[1] || node->flg.flg[3])
			{
				if (node->flg.flg[1])
					tmp[(ldbl->cursor)++] = '+';
				else
					ldbl->cursor++;
			}
			ldbl->zr = ldbl->len - ldbl->arg_len - ldbl->sign;
			while (ldbl->zr)
			{
				tmp[(ldbl->cursor)++] = '0';
				ldbl->zr--;
			}
			while (tmp[(ldbl->cursor)])
				tmp[(ldbl->cursor)++] = ldbl->arg[(ldbl->i)++];
		}
	}
	realloc_shape(node, tmp, ldbl->len);
	free(uni);
	free(ldbl);
}
