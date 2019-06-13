/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:19:10 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/13 22:15:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			sort_tab(int *arr, t_tmp_data **tab,int len)
{
	int			i;

	i = 0;
	merge_sort(arr, 0, (len - 1));
	while (i < len)
	{
		tab[i]->dlr = arr[i];
		i++;
	}
}

t_tmp_data		**cp_data(t_shape *lst, int len)
{
	t_tmp_data	**tab;
	t_tmp_data	*args;
	int			*arr;
	int			i;

	i = 0;
	args = NULL;
	tab = (t_tmp_data**)malloc(sizeof(t_tmp_data*) * len + 1);
	arr = (int*)malloc(sizeof(int) * len);
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
			args = add_node(args, lst->conv, lst->d.d_val);
			arr[i] = args->dlr;
			tab[i++] = args;
		}
		lst = lst->next;
	}
	sort_tab(arr, tab, len);
	return (tab);
}
