/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:40:15 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 19:41:05 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			l_init_spl_cs(t_shape *node, t_ldbl *uni, t_conv_dbl *ldbl)
{
	if (node->field_w.f_w >= ldbl->arg_len)
		ldbl->len = node->field_w.f_w;
	else if (ldbl->arg_len > node->field_w.f_w)
		ldbl->len = ldbl->arg_len;
	uni->ldbl = node->arg.l_dbl;
	ldbl->sign = uni->ldbl_d.sign;
	ldbl->i = 0;
	ldbl->cursor = 0;
	ldbl->arg = ldbl_dispatcher(node);
	ldbl->arg_len = ft_strlen(ldbl->arg);
	ldbl->len = ldbl->arg_len;
	ldbl->s_cse = l_spl_case(*uni);
	if (ldbl->s_cse == -1 || ldbl->s_cse == 1)
		node->flg.flg[2] = 0;
	if (ldbl->s_cse == 0)
	{
		node->flg.flg[1] = 0;
		node->flg.flg[2] = 0;
		node->flg.flg[3] = 0;
	}
	if (node->flg.flg[3] && node->flg.flg[1])
		node->flg.flg[3] = 0;
	if (node->flg.flg[2] && node->flg.flg[0])
		node->flg.flg[2] = 0;
}

void			l_flg_min_true(t_shape *node, char *tmp, t_conv_dbl *ldbl)
{
	if (ldbl->sign == 1)
		tmp[ldbl->cursor++] = '-';
	if (node->flg.flg[1] || node->flg.flg[3])
	{
		if (node->flg.flg[1] && !ldbl->sign)
			tmp[(ldbl->cursor)++] = '+';
		else if (node->flg.flg[3] && !ldbl->sign)
			ldbl->cursor++;
	}
	while (tmp[(ldbl->cursor)] && ldbl->arg_len--)
		tmp[(ldbl->cursor)++] = ldbl->arg[(ldbl->i)++];
}

void			l_flg_zero_flse(t_shape *node, char *tmp, t_conv_dbl *ldbl)
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

void			l_flg_zero_true(t_shape *node, char *tmp, t_conv_dbl *ldbl)
{
	if (ldbl->sign == 1)
		tmp[ldbl->cursor++] = '-';
	if ((node->flg.flg[1] || node->flg.flg[3]) && !ldbl->sign)
	{
		if (node->flg.flg[1])
			tmp[(ldbl->cursor)++] = '+';
		else
			ldbl->cursor++;
	}
	ldbl->zr = ldbl->len - ldbl->arg_len - ldbl->sign;
	if ((node->flg.flg[1] || node->flg.flg[3]) && !ldbl->sign)
		(ldbl->zr)--;
	while (ldbl->zr)
	{
		tmp[(ldbl->cursor)++] = '0';
		ldbl->zr--;
	}
	while (tmp[(ldbl->cursor)])
		tmp[(ldbl->cursor)++] = ldbl->arg[(ldbl->i)++];
}

void			conv_ldbl(t_shape *node)
{
	char		*tmp;
	t_ldbl		*uni;
	t_conv_dbl	*ldbl;

	uni = ft_memalloc(sizeof(t_ldbl));
	ldbl = ft_memalloc(sizeof(t_conv_dbl));
	l_init_spl_cs(node, uni, ldbl);
	if ((ldbl->len <= ldbl->arg_len) &&
			(node->flg.flg[1] || node->flg.flg[3] || ldbl->sign))
		ldbl->len++;
	tmp = ft_strnew(ldbl->len);
	tmp = ft_memset(tmp, ' ', ldbl->len);
	if (node->flg.flg[0])
		l_flg_min_true(node, tmp, ldbl);
	else
	{
		if (!node->flg.flg[2])
			l_flg_zero_flse(node, tmp, ldbl);
		else
			l_flg_zero_true(node, tmp, ldbl);
	}
	realloc_shape(node, tmp, ldbl->len);
	free(uni);
	multi_free(2, ldbl->arg, ldbl);
}
