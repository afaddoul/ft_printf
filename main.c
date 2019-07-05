/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 19:54:48 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>

int main()
{
	ft_printf("dyalna-1-|%.u|%-.u|%0.u\n", 0U, 0U, 0U);
	printf("dyalhom-1-|%.u|%-.u|%0.u\n", 0U, 0U, 0U);
	//ft_printf("dyalna-2|%u|\n", UINT_MAX);
	//printf("dyalhom-2|%u|\n", UINT_MAX);
	return (0);
}
