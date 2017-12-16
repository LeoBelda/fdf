/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:04:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/17 00:32:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_point(t_vec2c point, int *addr)
{
	int		i;
	int		j;

	i = -2;
	while(i < 3)
	{
		j = -2;
		while (j < 3)
		{
			if (pix_clip((t_vec2c){point.x + j, point.y + i, 0, 0}))
				addr[point.x + j + (point.y + i) * XWIN] = C_WHI;
			j++;
		}
		i++;
	}
}

void		draw_starbox(t_map *map, t_matrices *matrices, int *addr)
{
	size_t	i;

	i = 0;
	while (i < map->starbox_size)
	{
		map->starbox[i] = mat4xvec4(
				trsmat4vec(matrices->diff_eye_pos),
				map->starbox[i]);
		map->starproj[i] = mat4xvec4_tovec3(matrices->f_mat, map->starbox[i]);
		map->stardraw[i] = (t_vec2c)
			{ (map->starproj[i].x + 1.0) * X_WIN / 2.0,
			(map->starproj[i].y + 1.0) * Y_WIN / 2.0,
			C_WHI, 0.0};
		draw_point(map->stardraw[i], addr);
		i++;
	}
}
