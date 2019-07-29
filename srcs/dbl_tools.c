/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:03:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/29 17:29:02 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		adjust_len(t_nb *nb, t_optim *opt)
{
	if (nb->frac_len < opt->pre)
	{
		opt->tmp = ft_strdup(nb->frac_vl);
		free(nb->frac_vl);
		nb->frac_vl = ft_strnew(opt->pre);
		ft_memset(nb->frac_vl, '0', opt->pre);
		nb->frac_vl = cpy_str(nb->frac_vl, opt->tmp);
		free(opt->tmp);
	}
}

void		join_dbl_components(char **str, t_nb *nb, t_optim *opt)
{
	if ((int)ft_strlen(opt->frac_cpy) != nb->frac_len)
	{
		opt->tmp = nb->int_vl;
		nb->int_vl = add_op(nb->int_vl, "1");
		free(opt->tmp);
		opt->tmp = nb->int_vl;
		nb->int_vl = ft_strjoin(nb->int_vl, ".");
		free(opt->tmp);
		*str = ft_strjoin(nb->int_vl, (opt->frac_cpy + 1));
	}
	else
	{
		opt->tmp = nb->int_vl;
		nb->int_vl = ft_strjoin(nb->int_vl, ".");
		free(opt->tmp);
		*str = ft_strjoin(nb->int_vl, opt->frac_cpy);
	}
	multi_free(3, nb->int_vl, opt->frac_cpy, nb->frac_vl);
}

char		*cpy_str(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

t_nb		*ft_int_frac(char *str)
{
	t_nb	*nb;

	nb = ft_memalloc(sizeof(t_nb));
	while (str[nb->int_len] != '.' && str[nb->int_len])
		nb->int_len++;
	nb->int_vl = ft_strsub(str, 0, nb->int_len);
	nb->frac_len = nb->int_len;
	nb->frac_vl = ft_strdup("0");
	if (str[nb->int_len] == '.')
	{
		free(nb->frac_vl);
		while (str[nb->frac_len])
			nb->frac_len++;
		nb->frac_vl = ft_strsub(str, nb->int_len + 1,
				nb->frac_len - nb->int_len);
		nb->frac_len = ft_strlen(nb->frac_vl);
	}
	return (nb);
}
