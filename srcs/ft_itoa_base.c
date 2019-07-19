/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:32:58 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/18 18:38:15 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long long	nbrlen(unsigned long long nb, int base)
{
	int				len;

	len = nb == 0 ? 1 : 0;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char				*copy(char *s1, char *s2)
{
	int				i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

int					recursion(unsigned long long nbr, char *str, int base,
		int cse)
{
	int				i;
	static char		*arr = "0123456789abcdef";

	i = 0;
	if (nbr / base != 0)
		i = recursion(nbr / base, str, base, cse);
	if (cse)
		str[i++] = arr[nbr % base];
	else
		str[i++] = ft_toupper(arr[nbr % base]);
	str[i] = '\0';
	return (i);
}

char				*ft_itoa_base(unsigned long long nbr, int base, int cse)
{
	int				i;
	char			*str;

	i = nbrlen(nbr, base);
	str = ft_strnew(i);
	if (nbr == 0)
		return (copy(str, "0"));
	i = recursion(nbr, str, base, cse);
	return (str);
}
