/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:19:10 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/10 20:01:31 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_tmp_data		**cp_data(t_shape *lst, int len)
{
	t_tmp_data	*args;
	t_tmp_data	**arr;
	int			i;

	i = 0;
	args = NULL;
	arr = (t_tmp_data**)malloc(sizeof(t_tmp_data*) * len + 1);
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
			args = add_node(args, lst->conv, lst->d.d_val);
			arr[i++] = args;
		}
		lst = lst->next;
	}
	arr[i] = 0;
	merge_sort(arr, 0, (len - 1));
	return (arr);
}
