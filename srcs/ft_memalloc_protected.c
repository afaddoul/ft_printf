/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_protected.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:18:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 13:49:13 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_memalloc_protected(size_t size)
{
	void	*buff;

	buff = (void*)malloc(size);
	if (buff == NULL)
		exit(1);
	ft_bzero(buff, size);
	return (buff);
}
