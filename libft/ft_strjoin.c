/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:31:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/05 13:39:20 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		j;
	size_t		s1_len;
	size_t		s2_len;

	i = 0;
	if (!(s1 && s2))
		exit(1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ptr = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		exit(1);
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
