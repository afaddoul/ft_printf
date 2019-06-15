/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:02:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/15 12:02:11 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape		*ft_is_flg(t_shape *node, char *str, int *i)
{
	node->flg.f_flg = 1;
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == '0' ||
			str[*i] == ' ' || str[*i] == '#')
	{
		if (str[*i] == '-')
			node->flg.flg[0] = 1;
		if (str[*i] == '+')
			node->flg.flg[1] = 1;
		if (str[*i] == '0')
			node->flg.flg[2] = 1;
		if (str[*i] == ' ')
			node->flg.flg[3] = 1;
		if (str[*i] == '#')
			node->flg.flg[4] = 1;
		(*i)++;
	}
	return (node);
}

t_shape		*ft_is_dlr_or_fw(t_shape *node, char *str, int *i)
{
	char	*s;

	s = ft_strnew(0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		s = ft_joinchar(s, str[*i]);
		(*i)++;
	}
	if (str[*i] == '$')
		(*i)++;
	else
	{
		node->field_w.f_w_flg = 1;
		node->field_w.f_w = ft_atoi(s);
	}
	free(s);
	return (node);
}

t_shape		*ft_is_precision(t_shape *node, char *str, int *i)
{
	char	*s;

	s = ft_strnew(0);
	(*i)++;
	node->p.pre_flg = 1;
	if (str[*i] < '0' || str[*i] > '9')
	{
		node->p.pre = 0;
		return (node);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		s = ft_joinchar(s, str[*i]);
		(*i)++;
	}
	node->p.pre = ft_atoi(s);
	free(s);
	return (node);
}

t_shape		*ft_is_len_mod(t_shape *node, char *str, int *i)
{
	node->l_m.l_m_flg = 1;
	if (str[*i] == 'h' && str[((*i) + 1)] == 'h')
	{
		node->l_m.l_mod[0] = 'h';
		node->l_m.l_mod[1] = 'h';
	}
	else if (str[*i] == 'l' && str[((*i) + 1)] == 'l')
	{
		node->l_m.l_mod[0] = 'l';
		node->l_m.l_mod[1] = 'l';
	}
	else if (str[*i] == 'h')
		node->l_m.l_mod[0] = 'h';
	else if (str[*i] == 'l')
		node->l_m.l_mod[0] = 'l';
	else if (str[*i] == 'L')
		node->l_m.l_mod[0] = 'L';
	return (node);
}

t_shape		*parse_data(t_shape *node, char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			node = ft_is_dlr_or_fw(node, str, &i);
		if (str[i] == '-' || str[i] == '+' || str[i] == '0' ||
				str[i] == ' ' || str[i] == '#')
			node = ft_is_flg(node, str, &i);
		if (str[i] >= '1' && str[i] <= '9')
			node = ft_is_dlr_or_fw(node, str, &i);
		if (str[i] == '.' && str[i + 1] != '*')
			node = ft_is_precision(node, str, &i);
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
			node = ft_is_len_mod(node, str, &i);
		i++;
	}
	return (node);
}
