/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:22:24 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 16:07:28 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			conv_finder(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'o' &&
			c != 'u' && c != 'x' && c != 'X' && c != 'f' && c != '%')
		return (1);
	return (0);
}

void		stct_init(t_arg *v)
{
	v->dlr = 0;
	v->f_w_star = 0;
	v->pre_star = 0;
	v->dlr = 0;
	v->dlr_v = 0;
}

t_arg		*ft_is_str(char *str, int *i)
{
	t_arg	*tmp;

	if (!(tmp = (t_arg*)malloc(sizeof(t_arg))))
		exit(1);
	stct_init(tmp);
	tmp->buff = ft_strnew(0);
	while (str[*i] && (str[*i] != '%' || (str[*i] == '%' && str[*i + 1]
					&& str[*i + 1] == '%')))
	{
		if (str[*i] == '%' && str[*i + 1] == '%')
			(*i)++;
		tmp->buff = ft_joinchar(tmp->buff, str[*i]);
		if (str[*i] == '\0')
			break ;
		if (str[*i + 1] == '%')
			break ;
		(*i)++;
	}
	return (tmp);
}

t_arg		*ft_is_conv(char *str, int *i)
{
	t_arg	*tmp;
	int		start;

	if (!(tmp = (t_arg*)malloc(sizeof(t_arg))))
		exit(1);
	stct_init(tmp);
	tmp->buff = ft_strnew(0);
	start = *i;
	while (str[*i])
	{
		if (str[*i] == '$')
		{
			tmp = rec_d(str, tmp, start, *i);
			tmp->dlr = 1;
		}
		tmp->buff = ft_joinchar(tmp->buff, str[*i]);
		if (str[*i] == '*' && str[*i - 1] != '.')
			tmp->f_w_star = -1;
		else if (str[*i] == '.' && str[*i + 1] && str[*i + 1] == '*')
			tmp->pre_star = -1;
		if (conv_finder(str[*i]) == 0)
			break ;
		(*i)++;
	}
	return (tmp);
}

t_shape		*fill_list(t_shape *head, char *str)
{
	int		i;
	t_arg	*arg;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '%') || (str[i] == '%' && (str[i + 1] &&
						str[i + 1] == '%')))
		{
			arg = ft_is_str(str, &i);
			head = add_shape(head, 0, arg);
		}
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			arg = ft_is_conv(str, &i);
			arg->cv = str[i];
			head = add_shape(head, 1, arg);
		}
		if (str[i] != '\0')
			i++;
	}
	return (head);
}
