/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:51:10 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 16:00:51 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			check_null_p(t_shape *node)
{
	char	*tmp;
	char	*arg_cpy;
	int		i;

	i = 0;
	printf("here1\n");
	tmp = ft_strdup("0x0");
	arg_cpy = ft_strdup(node->arg.p);
	while (arg_cpy[i])
	{
		if (arg_cpy[i] != tmp[i])
			return (0);
		else
			i++;
	}
	free(tmp);
	return (1);
}
