/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:30:35 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 13:23:44 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			swap_str(char **s1, char **s2)
{
	char		*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static void		init_var(t_add **ad, char **str, char **s1, char **s2)
{
	*ad = ft_memalloc_protected(sizeof(t_add));
	(*ad)->i = 0;
	(*ad)->sum = 0;
	(*ad)->quotient = 0;
	if (ft_strlen(*s1) > ft_strlen(*s2))
		swap_str(s1, s2);
	(*ad)->len_1 = ft_strlen(*s1);
	(*ad)->len_2 = ft_strlen(*s2);
	*str = ft_strnew(((*ad)->len_1 > (*ad)->len_2) ? ((*ad)->len_1 + 1) :
			((*ad)->len_2 + 1));
	*s1 = ft_strrev(*s1);
	*s2 = ft_strrev(*s2);
}

char			*add_op(char *s1, char *s2)
{
	t_add	*ad;
	char	*str;

	init_var(&ad, &str, &s1, &s2);
	while (ad->i < ad->len_1)
	{
		ad->sum = (s1[ad->i] - '0') + (s2[ad->i] - '0') + ad->quotient;
		str[ad->i] = (ad->sum % 10) + '0';
		ad->quotient = ad->sum / 10;
		(ad->i)++;
	}
	while (ad->i < ad->len_2)
	{
		ad->sum = (s2[ad->i] - '0') + ad->quotient;
		str[ad->i] = (ad->sum % 10) + '0';
		ad->quotient = ad->sum / 10;
		(ad->i)++;
	}
	str[ad->i] = (ad->quotient) ? (ad->quotient + '0') : str[ad->i];
	ft_strrev(str);
	ft_memdel((void**)&ad);
	return (str);
}
