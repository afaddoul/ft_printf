/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:49:54 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/13 21:56:59 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** cp data to left array and right array
*/

void			cp_data_array1(int *arr, t_points *arrs, t_const *optim,
		int *i)
{
	i[0] = 0;
	while (i[0] < optim->n1)
	{
		arrs->left[i[0]] = arr[optim->l + i[0]];
		i[0]++;
	}
}

void			cp_data_array2(int *arr, t_points *arrs, t_const *optim,
		int *i)
{
	i[1] = 0;
	while (i[1] < optim->n2)
	{
		arrs->right[i[1]] = arr[optim->m + i[1] + 1];
		i[1]++;
	}
}

/*
**Merge the both arrays into arr
*/

void			merge_arrays(int *arr, t_points *arrs, t_const *optim, int *i)
{
	while (i[0] < (optim->m - optim->l + 1) && i[1] < (optim->r - optim->m))
	{
		if (arrs->left[i[0]] <= arrs->right[i[1]])
			arr[i[2]] = arrs->left[(i[0]++)];
		else
			arr[i[2]] = arrs->right[(i[1]++)];
		i[2]++;
	}
}

void			multi_free(int count, ...)
{
	va_list		ap;

	va_start(ap, count);
	while (count)
	{
		free(va_arg(ap, void*));
		count--;
	}
}

void			init_idx(int l, int *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = l;
}

/*
**n1 = m - l + 1
**n2 = r - m
**i = i[0];
**j = i[1];
**k = i[2];
*/
