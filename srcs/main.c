/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/13 13:29:10 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int main()
{
	int x = 101010;
	char  *str;
	char g = 'm';
	//double z = 12.236;

	str = ft_strdup("achraf");
	//printf("4768%3$dABCD%1$sABCD%4$cABC%2$f", str, z, x, g);
	//ft_printf("4768%3$2dABCD%1$sABCD%4$cABC%2$f", x, str, g, z);
	ft_printf("%2$d---%3$-0.*hf-=9-9-49%1$d2923-=%5$x923%4$s-=23-\n",x);
	g++;
	return (0);
}
