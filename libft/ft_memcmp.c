/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:23:37 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/07 20:11:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < n)
	{
		if ((ret = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]))
			break ;
		i++;
	}
	return (ret);
}
