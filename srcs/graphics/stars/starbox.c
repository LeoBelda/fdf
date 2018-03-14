/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:04:27 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/14 15:08:58 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_clip(t_vec3 elem)
{
	if (elem.x >= 1.0 || elem.x < -1.0
	|| elem.y >= 1.0 || elem.y < -1.0
	|| elem.z >= 1.0 || elem.z < -1.0)
		return (0);
	else
		return (1);
}

void		draw_starbox(t_map *map, t_matrices *matrices,
						t_colorset active, int *addr)
{
	size_t	i;
	t_mat4	starmat;

	i = 0;
	starmat = mat4xmat4(rotzmat4new(0.006), mat4xmat4(rotymat4new(0.005),
				mat4xmat4(rotxmat4new(0.002),
			trsmat4vec((t_vec4) {matrices->diff_eye_pos.x,
									matrices->diff_eye_pos.y,
									matrices->diff_eye_pos.z, 0.0}))));
	while (i < map->starbox_size)
	{
		map->starbox[i].pos = mat4xvec4(starmat, map->starbox[i].pos);
		map->starproj[i] = mat4xvec4_tovec3(matrices->f_mat,
									map->starbox[i].pos);
		if (in_clip(map->starproj[i]))
		{
			map->stardraw[i] = (t_vec2r)
				{ (map->starproj[i].x + 1.0) * X_WIN / 2.0,
				(map->starproj[i].y + 1.0) * Y_WIN / 2.0};
			map->starbox[i].draw(map->stardraw[i], active, addr);
		}
		i++;
	}
}
