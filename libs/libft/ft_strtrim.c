/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:52:16 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 11:38:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(s[i]))
	{
		if (!(str = ft_strnew(0)))
			return (NULL);
	}
	else
	{
		j--;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		if (!(str = ft_strsub(s, (unsigned int)i, j - i + 1)))
			return (NULL);
	}
	return (str);
}
