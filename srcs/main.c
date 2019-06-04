/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/04 05:04:00 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int main()
{
	int x = 3;
	int y = 4;
	char *str = "acharf";
	int c = 7;
	int v = 100;
	int g = 23;
	double z = 12.236;
	ft_printf("sgkhgs%LXdknfd%.9ldcnds%5hcvkjd%# -+0llufvn,dlij %3$3.89hhxdfk%4$Xmjhdf", x, y, str, c, v, g, z);
	return (0);
}
