/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:16:00 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/30 19:39:32 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plain_background(int *addr, int color)
{
	long int	longcolor;

	ft_intset(&longcolor, color, 2);
	ft_lintset(addr, longcolor, XWIN * YWIN / 2);
}

void	stripped_background(int *addr, int cola, int colb, size_t thick)
{
	long int	lcola;
	long int	lcolb;
	size_t		i;

	i = 0;
	ft_intset(&lcola, cola, 2);
	ft_intset(&lcolb, colb, 2);
	while (i < YWIN / thick)
	{
		if (i % 2)
			ft_lintset(&(addr[i * thick * XWIN]), lcola, (XWIN / 2) * thick);
		else
			ft_lintset(&(addr[i * thick * XWIN]), lcolb, (XWIN / 2) * thick);
		i++;
	}
}
