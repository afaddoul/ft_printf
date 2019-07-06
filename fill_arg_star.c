/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:37:05 by afaddoul          #+#    #+#             */
/*   Updated: 2019/05/25 04:15:50 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_shape 	*fill_arg_star(t_shape *head, int f_w, int pre)
{
	head->field_w.f_w_flg = f_w;
	head->p.pre_flg = pre;
	return (head);
}
