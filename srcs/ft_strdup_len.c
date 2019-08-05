/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:08:14 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 13:32:22 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strdup_len(char *s1, int len)
{
	char	*pointer;
	int		i;

	i = 0;
	pointer = ft_memalloc_protected(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	while (i < len)
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
