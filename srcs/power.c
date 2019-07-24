/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:03:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/24 13:08:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

char		*ft_str_power(char *base, int pow)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	if (pow == 0)
		return (ft_strdup("1"));
	if (pow == 1)
		return (ft_strdup(base));
	str = ft_strdup(base);
	while (i < pow)
	{
		tmp = str;
		str = multi_op(str, base);
		ft_strdel(&tmp);
		i++;
	}
	return (str);
}
