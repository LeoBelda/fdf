/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:21:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 06:17:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len_d;
	size_t	i;

	len_d = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[len_d + i] = s2[i];
		i++;
	}
	s1[len_d + i] = 0;
	return (s1);
}
