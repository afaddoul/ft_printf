/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:27:05 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/25 17:24:48 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*cpy_arg(char *dst, char *src, int i)
{
	int	len;
	int j;

	j = 0;
	if (i == 0)
		len = ft_strlen(src);
	else
		len = ft_strlen(dst);
	while (i < len)
	{
		dst[i++] = src[j++];
	}
	return (dst);
}
