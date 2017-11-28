/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:44:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 13:14:24 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_clip(t_vec3 elem)
{
	if (elem.x >= 1.0 || elem.x < -1.0
	 || elem.y >= 1.0 || elem.y < -1.0
	 || elem.z >= 1.0 || elem.z < 0.0)
	{
		if (elem.z >= 1.0 || elem.z < 0.9)
			return (2);
		else
			return (1);
	}
	return (0);
}

void		vertices_to_proj(t_map *map, t_mat4 f_mat)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->proj[i] = mat4xvec4_tovec3(f_mat, map->vertices[i]);
		map->clip[i] = in_clip(map->proj[i]);
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
						{ (map->proj[i].x + 1.0) * X_WIN / 2.0,
						 (map->proj[i].y + 1.0) * Y_WIN / 2.0,
						 get_color(map->min_z, map->max_z,
									(int)map->vertices[i].z, active) };
		i++;
	}
}

void		draw_to_img(t_map *map, int *addr)
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
				if (!map->clip[i] || !map->clip[i +1])
				{
					if (!map->clip[i] && !map->clip[i + 1])
						draw_line(map->draw[i], map->draw[i + 1], addr);
					else if (map->clip[i] != 2 && map->clip[i + 1] != 2)
						draw_clipline(map->draw[i], map->draw[i + 1], addr);
				}
			if (y + 1 < map->nb_line)
				if (!map->clip[i] || !map->clip[i + map->nb_col])
				{
					if (!map->clip[i] && !map->clip[i + map->nb_col])
						draw_line(map->draw[i], map->draw[i + map->nb_col], addr);
					else if (map->clip[i] != 2 && map->clip[i + map->nb_col] != 2)
						draw_clipline(map->draw[i], map->draw[i + map->nb_col], addr);
				}
			i++;
			x++;
		}
		y++;
	}
}
