/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/04 04:57:29 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_shape 	*lst;
	t_shape 	*tmp;
	char 		*frm;
	int 		i;

	lst = NULL;
	i = 1;
	va_start(ap, format);
	frm = ft_strdup((char*)(format));
	lst = fill_list(lst, frm);
	printf("%p\n", lst);
	lst = parse_arg(lst, &ap);
	//lst = swap_dlr(lst);
	printf("%p\n", lst);
	tmp = lst;
	printf("%p\n", tmp);
		printf("lst_len:%d\n", lst->lst_len);
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
		printf("->node:%d<-\n", i);
		printf("----------------------\n");
		printf("index:%d\n", lst->index);
		printf("lst_len:%d\n", lst->lst_len);
		printf("flag:%d\n", lst->conv_flag);
		printf("|%s|\n", lst->shape);
		printf("dlr$flg|%d|\n", lst->d.dlr_flg);
		printf("dlr$val|%d|\n", lst->d.d_val);
		printf("flag_flg:|%d|\n", lst->flg.f_flg);
		printf("flags->>>-:|%d|,+:|%d|,0:|%d|,sp:|%d|,#:|%d|\n",
				lst->flg.flg[0],lst->flg.flg[1],lst->flg.flg[2],
				lst->flg.flg[3],lst->flg.flg[4]);
		printf("field_width_flg:|%d|\n", lst->field_w.f_w_flg);
		printf("f_w|%d|\n", lst->field_w.f_w);
		printf("precision:_flg|%d|\n", lst->p.pre_flg);
		printf("pre|%d|\n", lst->p.pre);
		printf("L_M_FLG|%d|\n", lst->l_m.l_m_flg);
		printf("L_M_|%s|\n", lst->l_m.l_mod);
		printf("conv:|%c|\n", lst->conv);
		printf("------\n");
		printf("arg.d|%d|\n", lst->arg.d);
		printf("arg.s|%s|\n", lst->arg.s);
		printf("arg.i|%d|\n", lst->arg.i);
		printf("arg.f|%f|\n", lst->arg.f);
		printf("------\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~\n");
			i++;
		if (lst->next)
		printf("     |\n     |\n     |\n     |\n     |\n     |\n     |\n");
		}
		printf("\n");
			lst = lst->next;
	}
	printf("after:%p\n", tmp);
	printf("first_node:lst_len|%d|\n", tmp->lst_len);
	printf("%s\n",format);/*
	printf("\n\n\n|||||||||||||||||||\"after\"||||||||||||||||||||\n\n\n");
	lst = swap_dlr(tmp);
	lst->flg.flg[0] = 'X';
	printf("|||||||||l_m|%d|||||||||\n", lst->flg.f_flg);
	while (lst)
	{
		if (lst->conv_flag == 1)
		{
		//printf("->node:%d<-\n", i);
		printf("----------------------\n");
		printf("index:%d\n", lst->index);
		printf("lst_len:%d\n", lst->lst_len);
		printf("flag:%d\n", lst->conv_flag);
		printf("|%s|\n", lst->shape);
		printf("conv:|%c|\n", lst->conv);
		printf("field_width:|%d|\n", lst->field_w.f_w_flg);
		printf("precision:|%d|\n", lst->p.pre_flg);
		printf("dlr$flg|%d|\n", lst->d.dlr_flg);
		printf("dlr$val|%d|\n", lst->d.d_val);
		printf("f_w|%d|\n", lst->field_w.f_w);
		printf("pre|%d|\n", lst->p.pre);
		printf("arg.d|%d|\n", lst->arg.d);
		printf("arg.s|%s|\n", lst->arg.s);
		printf("arg.i|%d|\n", lst->arg.i);
		printf("arg.f|%f|\n", lst->arg.f);
		printf("~~~~~~~~~~~~~~~~~~~~~~\n");
		if (lst->next)
		printf("     |\n     |\n     |\n     |\n     |\n     |\n     |\n");
		}
		printf("\n");
			lst = lst->next;
			i++;
	}
	printf("after:%p\n", tmp);
	printf("first_node:lst_len|%d|\n", tmp->lst_len);*/
	printf("|||%s|||\n",format);
	return (1);
}
