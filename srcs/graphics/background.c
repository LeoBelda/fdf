/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:16:00 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 07:42:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plain_background(int *addr, int colora)
{
	long int	longcolor;

	ft_intset(&longcolor, colora, 2);
	ft_lintset(addr, longcolor, XWIN * YWIN / 2);
}

void	no_background(int *addr, int colora)
{
	(void)addr;
	(void)colora;
}

void	stripped_background(int *addr, int cola, int colb)
{
	long int	lcola;
	long int	lcolb;
	size_t		i;

	i = 0;
	ft_intset(&lcola, cola, 2);
	ft_intset(&lcolb, colb, 2);
	while (i < YWIN / 50)
	{
		if (i % 2)
			ft_lintset(&(addr[i * 50 * XWIN]), lcola, (XWIN / 2) * 50);
		else
			ft_lintset(&(addr[i * 50 * XWIN]), lcolb, (XWIN / 2) * 50);
		i++;
	}
}
