/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/25 20:49:03 by afaddoul         ###   ########.fr       */
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
	ft_printf("|%.5s|", NULL);
	return (0);
}
