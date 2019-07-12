/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:07:37 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/11 10:49:27 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_arg		*rec_d(char *str, t_arg *arg, int start, int end)
{
	char	*s1;

	s1 = ft_strsub(str, start, end - start);
	arg->dlr_v = ft_atoi(s1);
	free(s1);
	return (arg);
}
