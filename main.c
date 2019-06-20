/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:20:32 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main()
{
	char c;
	char c1;

	c = 0;
	c1 = 0;
	ft_printf("achraf|%c|unity|%c|data\n", c, c1);
	printf("achraf|%c|unity|%c|data\n", c, c1);
	return (0);
}
