/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_interi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:17:07 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 03:49:11 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_rgb	rgb_interi(t_rgb c1, t_rgb c2, int distance, int progress)
{
	t_rgb	inter;

	if (distance == 0)
		return (c1);
	inter.a = 0;
	inter.r = c1.r + (progress * (c2.r - c1.r)) / distance;
	inter.g = c1.g + (progress * (c2.g - c1.g)) / distance;
	inter.b = c1.b + (progress * (c2.b - c1.b)) / distance;
	return (inter);
}
