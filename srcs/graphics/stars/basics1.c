/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stardraw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:06:27 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/14 15:07:41 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_star_10(t_vec2r point, t_colorset cl, int *addr)
{
	if (pix_clipr(point))
		addr[point.x + point.y * XWIN] = cl.st1;
}

void	draw_star_11(t_vec2r point, t_colorset cl, int *addr)
{
	if (pix_clipr(point))
		addr[point.x + point.y * XWIN] =
			rgb_mix((t_rgb)cl.st1, (t_rgb)cl.bg1, 0.5).i;
}

void	draw_star_p0(t_vec2r point, t_colorset cl, int *addr)
{
	int		i;
	int		j;

	i = -3;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			if (pix_clipr((t_vec2r){point.x + j, point.y + i}))
				addr[point.x + j + (point.y + i) * XWIN] =
					rgb_mix((t_rgb)cl.st1, (t_rgb)cl.bg1,
							(iabs(j) + iabs(i)) / 6.0).i;
			j++;
		}
		i++;
	}
}

void	draw_star_p1(t_vec2r point, t_colorset cl, int *addr)
{
	int		i;
	int		j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (pix_clipr((t_vec2r){point.x + j, point.y + i}))
				addr[point.x + j + (point.y + i) * XWIN] =
					rgb_mix((t_rgb)cl.st1, (t_rgb)cl.bg1,
							(iabs(j) + iabs(i)) / 2.0).i;
			j++;
		}
		i++;
	}
}
