/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:11:03 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/10 14:13:13 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_n;

	i = 0;
	if (!(needle[i]))
		return ((char*)haystack);
	len_n = ft_strlen(needle);
	while (haystack[i] && (int)i < (int)(len - len_n + 1))
	{
		if (ft_strncmp(&(haystack[i]), needle, len_n) == 0)
			return ((char*)&(haystack[i]));
		i++;
	}
	return (NULL);
}
