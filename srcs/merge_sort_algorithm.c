/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:24:56 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/19 16:37:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			merge(t_tmp_data **arr, int l, int m, int r)
{
	t_points	*arrs;
	t_const		optim;
	int			i[3];

	optim.l = l;
	optim.m = m;
	optim.r = r;
	optim.n1 = optim.m - optim.l + 1;
	optim.n2 = optim.r - optim.m;
	arrs = (t_points*)malloc(sizeof(t_points));
	arrs->left = (t_tmp_data **)malloc(sizeof(t_tmp_data *) * optim.n1);
	arrs->right = (t_tmp_data **)malloc(sizeof(t_tmp_data *) * optim.n2);
	cp_data_array_right(arr, arrs, &optim, &i[0]);
	cp_data_array_left(arr, arrs, &optim, &i[1]);
	init_idx(optim.l, i);
	merge_arrays(arr, arrs, &optim, i);
	while (i[0] < (optim.m - optim.l + 1))
	{
		arr[(i[2]++)] = arrs->left[(i[0]++)];
	}
	while (i[1] < (optim.r - optim.m))
	{
		arr[i[2]++] = arrs->right[i[1]++];
	}
	multi_free(3, arrs->left, arrs->right, arrs);
}

void			merge_sort(t_tmp_data **arr, int l, int r)
{
	int			m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
