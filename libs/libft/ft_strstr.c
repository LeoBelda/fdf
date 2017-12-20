/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:35:10 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 04:47:59 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (!(needle[i]))
		return ((char*)haystack);
	while (haystack[i])
	{
		if (ft_strncmp(&(haystack[i]), needle, ft_strlen(needle)) == 0)
			return ((char*)&(haystack[i]));
		i++;
	}
	return (NULL);
}
