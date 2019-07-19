/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:03:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/19 22:14:58 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

char		*ft_str_power(char *base, char *pow)
{
	int		i;
	int		power;
	char	*str;
	char	*tmp;

	i = 1;
	power = ft_atoi(pow);
	if (power == 0)
		return (ft_strdup("1"));
	if (power == 1)
		return (ft_strdup(base));
	str = ft_strdup(base);
	while (i < power)
	{
		tmp = str;
		str = multi_op(str, base);
		ft_strdel(&tmp);
		i++;
	}
	return (str);
}
/*
   void	ft_delnl(char *str)
   {
   size_t	len;

   len = ft_strlen(str);
   if (len != 0 && *(str + len - 1) == '\n')
 *(str + len - 1) = '\0';
 }

 int		main(void)
 {
 char	*base;
 char	*power;
 char	*result;
 size_t	size;

 base = NULL;
 power = NULL;
 size = 0;
 while (1)
 {
 if (getline(&base, &size, stdin) <= 0)
 return (1);
 if (getline(&power, &size, stdin) <= 0)
 return (1);
 ft_delnl(base);
 ft_delnl(power);
 result = ft_str_power(base, power);
 printf("%s\n%s\n%s\n", base, power, result);
 ft_strdel(&base);
 ft_strdel(&power);
 ft_strdel(&result);
 }
 return (0);
 }
 */
