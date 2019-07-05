/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:15:03 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 18:18:01 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libftprintf.h"

char	*ft_unsigned_itoa(unsigned long long n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(ptr = ft_strnew(ft_unsigned_nb_len(n))))
		return (0);
	ptr[i++] = (n % 10) + 48;
	while ((n /= 10) != 0)
		ptr[i++] = (n % 10) + 48;
	ptr[i] = '\0';
	return (ft_strrev(ptr));
}
