/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismemzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 06:59:58 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 07:22:06 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismemzero(void *mem, size_t n)
{
	while (n--)
		if (((unsigned char*)mem)[n])
			return (0);
	return (1);
}
