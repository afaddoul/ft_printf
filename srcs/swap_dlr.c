/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_dlr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 21:34:56 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/01 22:09:23 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int 		ft_cmp(int i, int j)
{
	if (j > i)
		return (1);
	else if (j < i)
		return (-1);
	else
		return (0);
}

int 		ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void		swap(char *x, char *y)
{
	char tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}	

t_shape		*ft_swap_conv(t_shape *lst)
{
	int 	i;
	int 	j;
	int 	skip;
	int 	drt;
	t_shape *tmp;

	i = ((lst->index) + 1);
	j = lst->d.d_val;
	printf("index: %d---dollar:%d---\n", i, j);
	tmp = lst;
	drt = ft_cmp(i, j);
	skip = ft_abs(i - j);
	printf("drt:%d+++skip:%d+++\n",drt, skip);
	while ((drt == -1 ? lst->prev : lst->next))
	{
		if (skip == 0)
			swap(&(tmp->conv), &(lst->conv));
		if (drt == 1)
		{
			if (lst->conv_flag == 1)
				skip--;
			lst = lst->next;
		}
		else if (drt == -1)
		{
			if (lst->conv_flag == 1)
				skip--;
			lst = lst->prev;
		}
		else if (drt == 0)
			break ;
	}
	return (tmp);
}

t_shape		*swap_dlr(t_shape *lst)
{
	t_shape *tmp;
	int len;

	tmp = lst;
	len = ((lst->lst_len) + 1);
	while (len)
	{
		while (lst)
		{
			if (lst->conv_flag == 1)
			{
				printf("Looped once\n");
				ft_swap_conv(lst);
			}
			lst = lst->next;
		}
		len--;
	}
	return (tmp);
}
