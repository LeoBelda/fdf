/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_interi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:17:07 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 22:53:27 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_rgb	rgb_interi(t_rgb c1, t_rgb c2, int distance, int progress)
{
	t_rgb	inter;
	int		ratio;

	if (distance == 0)
		return (c1);
	ratio = progress * 100 / distance;
	inter.a = 0;
	inter.r = c1.r + (ratio * (c2.r - c1.r)) / 100;
	inter.g = c1.g + (ratio * (c2.g - c1.g)) / 100;
	inter.b = c1.b + (ratio * (c2.b - c1.b)) / 100;
	return (inter);
}
