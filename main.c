/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:51:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/31 22:33:33 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main()
{
	double f;


	ft_printf("|%-+8.14f|%-+#8.14f|%-+ #08.14f|\n",INFINITY, INFINITY, INFINITY);
	printf("|%-+8.14f|%-+#8.14f|%-+ #08.14f|\n", INFINITY, INFINITY, INFINITY);
}
