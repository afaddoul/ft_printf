/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:41 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main()
{
	char c;
	char c1;
	char fw1;
	char fw2;

	c = 0;
	c1 = 0;
	fw1 = 5;
	fw2 = 10;
	ft_printf("%5p", NULL);
	printf("|%5p|\n", NULL);
	   char *str = "achraf";
	   ft_printf("|%10p|\n",str);
	   printf("|%10p|\n",str);
	return (0);
}
