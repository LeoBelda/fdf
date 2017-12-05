/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:44:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 23:06:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_clip(t_vec3 elem)
{
	if (elem.x >= 1.0 || elem.x < -1.0
	|| elem.y >= 1.0 || elem.y < -1.0
	|| elem.z >= 1.0 || elem.z < -1.0)
	{
		if (elem.z >= 1.0 || elem.z < -1.0)
			return (2);
		else
			return (1);
	}
	return (0);
}

void		vertices_to_proj(t_map *map, t_mat4 f_mat)
{
	size_t	i;
	t_vec4	*vertices;

	i = 0;
	vertices = map->mod_vertices;
	while (i < map->nb_vtx)
	{
		map->proj[i] = mat4xvec4_tovec3(f_mat, vertices[i]);
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
						(int)map->vertices[i].z, active),
			map->distancesxz[i] };
		i++;
	}
}

void		draw_line(t_map *map, int *addr, size_t i, size_t j)
{
	if ((!map->clip[i] || !map->clip[j]) && 
			((float)map->draw[i].dst < map->viewdist_active ||
			 (float)map->draw[j].dst < map->viewdist_active))
	{
		if (!map->clip[i] && !map->clip[j])
			bresenham(map->draw[i], map->draw[j], addr);
		else if (map->clip[i] != 2 && map->clip[j] != 2)
			bresenham_clip(map->draw[i], map->draw[j], addr);
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
				draw_line(map, addr, i, i + 1);
			if (y + 1 < map->nb_line)
				draw_line(map, addr, i, i + map->nb_col);
			i++;
			x++;
		}
		y++;
	}
}
