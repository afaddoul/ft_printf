/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/12 18:14:54 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>

int main()
{
ft_printf("+++|%#23.5hho|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
printf( "---|%-#23.5hho|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
ft_printf( "+++|%-#23.5hho|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
printf("---|%#23.5hho|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	return (0);
}
