/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:44:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 02:05:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertices_to_proj(t_map *map, t_mat4 f_mat)
{
	size_t	i;
	t_vec4	tmp;

	i = 0;
	while (i < map->nb_vtx)
	{
		tmp = mat4xvec4(f_mat, map->vertices[i]);
		map->proj[i] = (t_vec3) {tmp.x / tmp.w, tmp.y / tmp.w,
										tmp.z / tmp.w};
		i++;
	}
}

void		proj_to_draw(t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->draw[i] = (t_vec2c)
						{(map->proj[i].x + 1.0) * X_WIN / 2.0,
						 (map->proj[i].y + 1.0) * Y_WIN / 2.0,
						 get_color(map->min_z, map->max_z,
									map->vertices[i].z, active)};
		i++;
	}
}

static int	in_clip(t_vec3 elem)
{
	if (elem.x >= 1.0 || elem.x < -1.0
	 || elem.y >= 1.0 || elem.y < -1.0 
	 || elem.z >= 1.0 || elem.z < 0.0)
		return (0);
	else
		return (1);
}

void		draw_to_img(t_map *map, t_img *imginf)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (y < map->nb_line)
	{
		x = 0;
		while (x < map->nb_col)
		{
			if (x + 1 < map->nb_col)
			{
				if (in_clip(map->proj[i]) && in_clip(map->proj[i + 1]))
					draw_line(map->draw[i], map->draw[i + 1], *imginf);
				else if (in_clip(map->proj[i]) ||
						 in_clip(map->proj[i + 1]))
					draw_clipline(map->draw[i], map->draw[i + 1], *imginf);
			}
			if (y + 1 < map->nb_line)
			{
				if (in_clip(map->proj[i]) && in_clip(map->proj[i + map->nb_col]))
					draw_line(map->draw[i], map->draw[i + map->nb_col], *imginf);
				else if (in_clip(map->proj[i]) || 
						 in_clip(map->proj[i + map->nb_col]))
					draw_clipline(map->draw[i], map->draw[i + map->nb_col], *imginf);
			}
			i++;
			x++;
		}
		y++;
	}
}
