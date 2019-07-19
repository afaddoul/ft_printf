/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:01:06 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/19 15:06:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_multi			*init_var(t_multi *mul, char **str, char **s1, char **s2)
{
	mul = (t_multi*)malloc(sizeof(t_multi));
	mul->i = 0;
	mul->j = 0;
	mul->tmp = 0;
	mul->quotient = 0;
	mul->tmp = 0;
	mul->len_1 = ft_strlen(*s1);
	mul->len_2 = ft_strlen(*s2);
	*str = ft_strnew(mul->len_1 + mul->len_2);
	*s1 = ft_strrev(*s1);
	*s2 = ft_strrev(*s2);
	*str = ft_strnew(mul->len_1 + mul->len_2);
	ft_memset(*str, '0', (mul->len_1 + mul->len_2));
	return (mul);
}

char			*multi_op(char *s1, char *s2)
{
	t_multi		*mul;
	char		*str;

	mul = NULL;
	mul = init_var(mul, &str, &s1, &s2);
	while (mul->i < mul->len_1)
	{
		mul->j = 0;
		mul->quotient = 0;
		while (mul->j < mul->len_2)
		{
			mul->tmp = str[mul->i + mul->j] - '0' + mul->quotient;
			str[mul->i + mul->j] = (((str[mul->i + mul->j] - '0')
						+ ((s1[mul->i] - '0') * (s2[mul->j] - '0'))
						+ mul->quotient) % 10) + '0';
			mul->quotient = (mul->tmp + ((s1[mul->i] - '0')
						* (s2[mul->j] - '0'))) / 10;
			mul->j++;
		}
		str[mul->i + mul->j] = mul->quotient + '0';
		mul->i++;
	}
	str[mul->i + mul->j - 1] = mul->quotient + '0';
	str = ft_strrev(str);
	return (str);
}
