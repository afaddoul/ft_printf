/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:40:15 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/30 20:36:09 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void 			conv_dbl(t_shape *node)
{
	char 		*tmp;
	t_dbl		*uni;
	t_conv_dbl	*dbl;

	uni = ft_memalloc(sizeof(t_dbl));
	dbl = ft_memalloc(sizeof(t_conv_dbl));
	uni->dbl = node->arg.dbl;
	dbl->sign = uni->dbl_d.sign;
	dbl->i = 0;
	dbl->arg = dbl_dispatcher(node);
	dbl->arg_len = ft_strlen(dbl->arg);
	dbl->len = dbl->arg_len;
	if (node->flg.flg[3] && node->flg.flg[1])
		node->flg.flg[3] = 0;
	if (node->flg.flg[2] && node->flg.flg[0])
		node->flg.flg[2] = 0;
	if (node->flg.flg[0] && node->flg.flg[1])
		node->flg.flg[0] = 0;
	if (node->field_w.f_w >= dbl->arg_len)
		dbl->len = node->field_w.f_w;
	else if (dbl->arg_len > node->field_w.f_w)
		dbl->len = dbl->arg_len;
	tmp = ft_strnew(dbl->len);
	tmp = ft_memset(tmp, ' ', dbl->len);
	if (node->flg.flg[0])
	{
		if (dbl->sign == 1)
			tmp[dbl->cursor++] = '-';
		if (node->flg.flg[1] || node->flg.flg[3])
		{
			if (node->flg.flg[1])
				tmp[(dbl->cursor)++] = '+';
			else
				dbl->cursor++;
		}
		else
		{
			while (tmp[(dbl->cursor)])
				tmp[(dbl->cursor)++] = dbl->arg[(dbl->i)++];
		}
	}
	else
	{
		if (!node->flg.flg[2])
		{
			dbl->cursor = dbl->len - dbl->arg_len - dbl->sign;
			if (dbl->sign == 1)
				tmp[dbl->cursor++] = '-';
			if (node->flg.flg[1] || node->flg.flg[3])
			{
				if (node->flg.flg[1])
					tmp[(dbl->cursor)++] = '+';
				else
					dbl->cursor++;
			}
			else
			{
				(dbl->cursor)++;
				while (tmp[(dbl->cursor)])
					tmp[(dbl->cursor)++] = dbl->arg[(dbl->i)++];
			}
		}
		else
		{
			if (dbl->sign == 1)
				tmp[dbl->cursor++] = '-';
			if (node->flg.flg[1] || node->flg.flg[3])
			{
				if (node->flg.flg[1])
					tmp[(dbl->cursor)++] = '+';
				else
					dbl->cursor++;
			}
			dbl->zr = dbl->len - dbl->arg_len - dbl->sign;
			while (dbl->zr)
			{
				tmp[(dbl->cursor)++] = '0';
				dbl->zr--;
			}
			while (tmp[(dbl->cursor)])
				tmp[(dbl->cursor)++] = dbl->arg[(dbl->i)++];
		}
	}
	realloc_shape(node, tmp, dbl->cursor);
	free(uni);
	free(dbl);
}
