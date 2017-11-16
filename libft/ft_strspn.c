/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:58:43 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/10 18:20:05 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (s[count])
	{
		i = 0;
		while (charset[i])
		{
			if (s[count] == charset[i])
				break ;
			i++;
			if (!charset[i])
				return (count);
		}
		count++;
	}
	return (count);
}
