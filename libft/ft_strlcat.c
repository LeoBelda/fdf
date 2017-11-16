/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:26:18 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 01:29:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	ret;
	size_t	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size < len_d)
		ret = len_s + size;
	else
		ret = len_s + len_d;
	i = 0;
	while ((int)(len_d + i) < (int)size - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = 0;
	return (ret);
}
