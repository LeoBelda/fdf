/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_vtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 05:53:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 10:03:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2r		get_new_middle(t_map *map)
{
	int		rel_x;
	int		rel_y;

	rel_x = (int)map->closest_vtx_i % SIDE - SIDE / 2;
	rel_y = (int)map->closest_vtx_i / SIDE - SIDE / 2;
	return ((t_vec2r) { map->middle.x + rel_x, map->middle.y + rel_y });
}

static int	get_trs_factor(int i, int middle, int max)
{
	int	fct;

	if (middle + (i - SIDE / 2) > 0 || (middle + (i - SIDE / 2)) % max == 0)
		fct = (middle + (i - SIDE / 2)) / max;
	else
		fct = ((middle + (i - SIDE / 2)) / max) - 1;
	return (fct);
}

void		get_active_vertices(t_map *map)
{
	int		i;
	int		j;
	int		hrz_f;
	int		vrt_f;

	i = 0;
	if (map->infmode == INF_OFF)
		return ;
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			map->vertices[j + i * SIDE] = map->vertices_glb
				[imod(((map->middle.x + (j - SIDE / 2))), (int)map->nb_col_glb)
				+ imod((map->middle.y + (i - SIDE / 2)), (int)map->nb_line_glb)
					* (int)map->nb_col_glb];
			hrz_f = get_trs_factor(j, map->middle.x, (int)map->nb_col_glb);
			vrt_f = get_trs_factor(i, map->middle.y, (int)map->nb_line_glb);
			map->vertices[j + i * SIDE] = mat4xvec4(trsmat4new(
				(double)(hrz_f * ((int)map->nb_col_glb) * 10),
				(double)(vrt_f * ((int)map->nb_line_glb) * 10), 0.0),
							map->vertices[j + i * SIDE]);
			j++;
		}
		i++;
	}
}

void		get_active_world(t_map *map)
{
	int		i;
	int		j;
	int		hrz_f;
	int		vrt_f;

	i = 0;
	if (map->infmode == INF_OFF)
		return ;
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			map->world_coords[j + i * SIDE] = map->world_coords_glb
				[imod(((map->middle.x + (j - SIDE / 2))), (int)map->nb_col_glb)
				+ imod((map->middle.y + (i - SIDE / 2)), (int)map->nb_line_glb)
					* (int)map->nb_col_glb];
			hrz_f = get_trs_factor(j, map->middle.x, (int)map->nb_col_glb);
			vrt_f = get_trs_factor(i, map->middle.y, (int)map->nb_line_glb);
			map->world_coords[j + i * SIDE] =
				mat4xvec4(trsmat4new((double)(hrz_f * ((int)map->nb_col_glb)
					* 10), 0.0, (double)(vrt_f * ((int)map->nb_line_glb) * 10)),
							map->world_coords[j + i * SIDE]);
			j++;
		}
		i++;
	}
}
