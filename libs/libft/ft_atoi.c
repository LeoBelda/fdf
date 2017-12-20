/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:50:56 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/08 08:41:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	int		n;

	i = 0;
	neg = 0;
	n = 0;
	while (ft_iswhitespace((int)str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_isdigit((int)(str[i])))
	{
		n *= 10;
		n += (str[i] - 48);
		i++;
	}
	return (neg ? -n : n);
}
