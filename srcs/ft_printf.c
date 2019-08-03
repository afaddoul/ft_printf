/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/02 17:53:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_printf(const char *format, ...)
{
	t_shape		*lst;
	t_tmp_data	**tab;
	char		*frm;
	int			ret;
	va_list		ap;

	lst = NULL;
	ret = 0;
	va_start(ap, format);
	frm = ft_strdup((char*)(format));
	lst = fill_list(lst, frm);
	free(frm);
	if (dlr_detector(lst))
	{
		tab = cp_data(lst, lst->lst_len);
		tab = fill_sorted_arr(tab, &ap);
		receive_dlr_args(lst, tab);
	}
	else
		parse_arg(lst, &ap);
	dispatcher(lst);
	ret = ret_counter(lst);
	print_shapes(lst);
	free_lst(lst);
	return (ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_shape		*lst;
	t_tmp_data	**tab;
	char		*frm;
	int			ret;
	va_list		ap;

	lst = NULL;
	ret = 0;
	va_start(ap, format);
	frm = ft_strdup((char*)(format));
	lst = fill_list(lst, frm);
	free(frm);
	if (dlr_detector(lst))
	{
		tab = cp_data(lst, lst->lst_len);
		tab = fill_sorted_arr(tab, &ap);
		receive_dlr_args(lst, tab);
	}
	else
		parse_arg(lst, &ap);
	dispatcher(lst);
	ret = ret_counter(lst);
	print_shapes_fd(lst, fd);
	free_lst(lst);
	return (ret);
}
