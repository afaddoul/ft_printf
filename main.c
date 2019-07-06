/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/06 11:08:00 by afaddoul         ###   ########.fr       */
=======
/*   Updated: 2019/07/05 15:46:33 by afaddoul         ###   ########.fr       */
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>

int main()
{
<<<<<<< HEAD
	ft_printf("dyalna-1-|%.u|%-.u|%0.u\n", 0U, 0U, 0U);
	printf("dyalhom-1-|%.u|%-.u|%0.u\n", 0U, 0U, 0U);
	//ft_printf("dyalna-2|%u|\n", UINT_MAX);
	//printf("dyalhom-2|%u|\n", UINT_MAX);
=======
	ft_printf("%-+23.5hhd|%- 23.5hhd|%-023.5hhd|%+ 23.5hhd|%+023.5hhd|% 023.5hhd|%-+ 023.5hhd", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
	return (0);
}
