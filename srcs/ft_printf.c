/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:17 by afaddoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/05 20:08:10 by afaddoul         ###   ########.fr       */
=======
/*   Updated: 2019/07/04 17:04:52 by afaddoul         ###   ########.fr       */
>>>>>>> 763309f30b4ea6c28da0b9458c18589c760da9c1
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
		lst = parse_arg(lst, &ap);
	lst = dispatcher(lst);
	ret = ret_counter(lst);
	print_shapes(lst);
	free_lst(lst);
	return (ret);
}
