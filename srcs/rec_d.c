/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:07:37 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/19 12:59:40 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_arg		*rec_d(char *str, t_arg *arg, int start, int end)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		diff;

	diff = end - start;
	s1 = ft_strdup(str);
	tmp = s1;
	s1 = ft_strsub(str, start, end);
	free(tmp);
	s2 = ft_strnew(0);
	while (start < end)
	{
		s2 = ft_joinchar(s2, str[start]);
		start++;
	}
	arg->dlr_v = ft_atoi(s2);
	multi_free(2, s1, s2);
	return (arg);
}
