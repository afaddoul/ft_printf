/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:32:58 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 20:48:26 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long nbrlen(unsigned long nb)
{
	int len;

	len = 0;
	while(nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char 		*copy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

int 		recursion(unsigned long nbr, char *str,int base, int cse)
{
	int 	i;
	char 	*arr;

	i = 0;
	arr = ft_strnew(16);
	arr = (cse == 1) ? ft_strcpy(arr, "0123456789abcdef") :
		ft_strcpy(arr, "0123456789ABCDEF");
	if(nbr / base != 0)
		i = recursion(nbr /base, str, base, cse);
	str[i++] = arr[nbr % base];
	str[i] = '\0';
		free(arr);
	return (i);
}

char 		*ft_itoa_base(unsigned long nbr, int base, int cse)
{
	int 	i;
	char 	*str;

	i = nbrlen(nbr);
	str = (char *)malloc(sizeof(char*) * (i + 1));
	if (nbr == 0)
		return (copy(str, "0"));
	i = recursion(nbr, str,base, cse);
	return (str);
}
