/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:15:17 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/20 19:08:07 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_shape 	*lst;
	t_shape 	*tmp;
	t_tmp_data 	**tab;
	char 		*frm;
	int 		ret;
	int 		i;
	int 		j;

	lst = NULL;
	ret = 0;
	i = 1;
	j = 0;
	va_start(ap, format);
	frm = ft_strdup((char*)(format));
	lst = fill_list(lst, frm);
	tmp = lst;
	free(frm);
	if (dlr_detector(tmp))
	{
		tab = cp_data(tmp, lst->lst_len);
		tab = fill_sorted_arr(tab, &ap);
		receive_dlr_args(lst, tab);
	}
	else
		lst = parse_arg(lst, &ap);
	lst = checker(lst);
	ret = ret_counter(lst);
	print_shapes(lst);
	/*	while (lst)
		{
	//	if (lst->conv_flag == 1)
	//	{
	printf("adr:%p\n", lst);
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
	printf("arg.c|%c|\n", lst->arg.c);
	printf("arg.f|%f|\n", lst->arg.f);
	printf("------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
	i++;
	if (lst->next)
	printf("     |\n     |\n     |\n     |\n     |\n     |\n     |\n");
	//	}
	printf("\n");
	lst = lst->next;
	}
	printf("after:%p\n", tmp);
	printf("first_node:lst_len|%d|\n", tmp->lst_len);*/
	return (ret);
}
