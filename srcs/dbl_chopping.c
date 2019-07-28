/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_chopping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:11:36 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/28 23:19:58 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		flse_ties_to_even(t_nb *nb, t_optim *opt)
{
	opt->i = 1;
	while (nb->frac_vl[opt->i])
	{
		if (nb->frac_vl[opt->i] != '0')
		{
			opt->tmp = nb->int_vl;
			nb->int_vl = add_op(nb->int_vl, "1");
			free(opt->tmp);
			break ;
		}
		(opt->i)++;
	}
	if (nb->frac_vl[opt->i] == '\0')
		if (((nb->int_vl[opt->round] - '0') % 2))
		{
			opt->tmp = nb->int_vl;
			nb->int_vl = add_op(nb->int_vl, "1");
			free(opt->tmp);
		}
}

void		precision_false(t_shape *node, char **str, t_nb *nb, t_optim *opt)
{
	opt->round = (ft_strlen(nb->int_vl) - 1);
	if (nb->frac_vl[0] > '5' && nb->frac_vl[0] <= '9')
	{
		opt->tmp = nb->int_vl;
		nb->int_vl = add_op(nb->int_vl, "1");
		free(opt->tmp);
	}
	else if (nb->frac_vl[0] == '5')
		flse_ties_to_even(nb, opt);
	*str = ft_strdup(nb->int_vl);
	if (node->flg.flg[4])
	{
		opt->tmp = *str;
		*str = ft_strjoin(*str, ".");
		free(opt->tmp);
	}
	multi_free(2, nb->frac_vl, nb->int_vl);
}

void		true_ties_to_even(t_nb *nb, t_optim *opt)
{
	opt->i = opt->pre + 1;
	while (nb->frac_vl[opt->i])
	{
		if (nb->frac_vl[opt->i] != '0')
		{
			opt->tmp = opt->frac_cpy;
			nb->frac_len = ft_strlen(opt->frac_cpy);
			opt->frac_cpy = add_op(opt->frac_cpy, "1");
			free(opt->tmp);
			break ;
		}
		opt->i++;
	}
	if (nb->frac_vl[opt->i] == '\0')
	{
		if (((nb->frac_vl[opt->round] - '0') % 2))
		{
			opt->tmp = opt->frac_cpy;
			nb->frac_len = ft_strlen(opt->frac_cpy);
			opt->frac_cpy = add_op(nb->frac_vl, "1");
			free(opt->tmp);
		}
	}
}

void		precision_true(t_shape *node, char **str, t_nb *nb, t_optim *opt)
{
	if (!node->p.pre_flg)
		opt->pre = 6;
	else
		opt->pre = node->p.pre;
	adjust_len(nb, opt);
	opt->round = (opt->pre - 1);
	opt->frac_cpy = ft_strdup_len(nb->frac_vl, opt->pre);
	nb->frac_len = ft_strlen(opt->frac_cpy);
	if (nb->frac_vl[opt->pre] > '5' && nb->frac_vl[opt->pre] <= '9')
	{
		nb->frac_len = ft_strlen(opt->frac_cpy);
		opt->tmp = opt->frac_cpy;
		opt->frac_cpy = add_op(opt->frac_cpy, "1");
		free(opt->tmp);
	}
	else if (nb->frac_vl[opt->pre] == '5')
		true_ties_to_even(nb, opt);
	nb->frac_len = ft_strlen(opt->frac_cpy);
	join_dbl_components(str, nb, opt);
}

char		*ft_chopping(t_shape *node, char *str)
{
	t_nb	*nb;
	t_optim *opt;

	opt = ft_memalloc(sizeof(t_optim));
	nb = ft_int_frac(str);
	if (node->p.pre_flg && node->p.pre == 0)
		precision_false(node, &str, nb, opt);
	else if (!node->p.pre_flg || (node->p.pre_flg && node->p.pre))
		precision_true(node, &str, nb, opt);
	free(nb);
	free(opt);
	return (str);
}
