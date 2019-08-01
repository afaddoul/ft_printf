/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_c_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:31:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/01 22:53:18 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_joinchar(char *s1, char c)
{
	char		**tmp;
	char		*ptr;
	size_t		i;
	size_t		s1_len;

	i = 0;
	if (!(s1))
		return (0);
	tmp = &s1;
	s1_len = ft_strlen(s1);
	ptr = ft_memalloc(sizeof(char) * (s1_len + 2));
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = c;
	ptr[i] = '\0';
	free(*tmp);
	return (ptr);
}
