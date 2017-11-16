/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:25:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/10 18:27:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
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
				return (count);
			i++;
			if (!charset[i])
				break ;
		}
		count++;
	}
	return (count);
}
