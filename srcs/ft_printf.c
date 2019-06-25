/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/25 09:33:05 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_shape 	*lst;
	t_tmp_data 	**tab;
	char 		*frm;
	int 		ret;

	lst = NULL;
	ret = 0;
	va_start(ap, format); //init va_arg
	frm = ft_strdup((char*)(format));//allocate for format
	lst = fill_list(lst, frm);//parse_data
	free(frm);
	if (dlr_detector(lst))//parse_args in dlr case
	{
		tab = cp_data(lst, lst->lst_len);//fill tab with node adrs
		tab = fill_sorted_arr(tab, &ap);//sort tab of node adrss
		receive_dlr_args(lst, tab);//fill main lis with args
	}
	else//parse_args
		lst = parse_arg(lst, &ap);
	lst = dispatcher(lst);//
	ret = ret_counter(lst);//count return value
	print_shapes(lst);//print result
	free_lst(lst);//free all nodes and there contents
	return (ret);
}
