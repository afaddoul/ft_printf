/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:23:29 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 15:46:33 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>

int main()
{
	ft_printf("%-+23.5hhd|%- 23.5hhd|%-023.5hhd|%+ 23.5hhd|%+023.5hhd|% 023.5hhd|%-+ 023.5hhd", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	return (0);
}
