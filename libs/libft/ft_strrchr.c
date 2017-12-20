/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:24:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 01:00:54 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[len] == (char)c)
		return ((char*)&(s[len]));
	while (len--)
		if (s[len] == (char)c)
			return ((char*)&(s[len]));
	return (NULL);
}
