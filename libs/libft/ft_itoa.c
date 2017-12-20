/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:38:32 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/09 12:28:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(long int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n < 10)
		return (size + 1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	long int		nb;
	size_t			len;
	size_t			i;

	nb = n;
	i = 0;
	len = ft_get_size(nb);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
		i++;
	}
	if (nb < 10)
		str[i] = nb + 48;
	else
		while (nb != 0)
		{
			str[--len] = nb % 10 + 48;
			nb /= 10;
		}
	return (str);
}
