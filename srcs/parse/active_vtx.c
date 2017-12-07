/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_vtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 05:53:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/07 14:55:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_new_middle(t_map *map)
{
	size_t	new_mid;
	size_t	rel_x;
	size_t	rel_y;

	rel_x = map->closest_vtx_i % SIDE - SIDE / 2;
	rel_y = map->closest_vtx_i / SIDE - SIDE / 2;
	new_mid = map->middle + rel_x + rel_y * map->nb_col_glb;
	ft_putnbr(rel_y);
	return (new_mid);
}

void	get_active_vertices(t_map *map)
{
	size_t	i;
	size_t	j;
	double	hrz_f;
	double	vrt_f;

	i = 0;
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			map->vertices[j + i * SIDE] = map->vertices_glb
				[((map->middle + (j - SIDE / 2))) % map->nb_col_glb
				+ ((map->middle / map->nb_col_glb +
					i - SIDE / 2) % map->nb_line_glb) * map->nb_col_glb];
			hrz_f = (map->middle % map->nb_col_glb + (j - SIDE / 2))
					/ map->nb_col_glb;
			vrt_f = (map->middle / map->nb_col_glb + (i - SIDE / 2))
					/ map->nb_line_glb;
			map->vertices[j + i * SIDE] =
				mat4xvec4(trsmat4new((double)(hrz_f * map->nb_col_glb * 10),
									(double)(vrt_f * map->nb_line_glb * 10), 0.0),
							map->vertices[j + i * SIDE]);
			j++;
		}
		i++;
	}
}

void	get_active_world(t_map *map)
{
	size_t	i;
	size_t	j;
	double	hrz_f;
	double	vrt_f;

	i = 0;
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			map->world_coords[j + i * SIDE] = map->world_coords_glb
				[((map->middle + (j - SIDE / 2)) % map->nb_col_glb)
				+ ((map->middle / map->nb_col_glb +
					i - SIDE / 2) % map->nb_line_glb) * map->nb_col_glb];
			hrz_f = (map->middle % map->nb_col_glb + (j - SIDE / 2))
					/ map->nb_col_glb;
			vrt_f = (map->middle / map->nb_col_glb + (i - SIDE / 2))
					/ map->nb_line_glb;
			map->world_coords[j + i * SIDE] =
				mat4xvec4(trsmat4new((double)hrz_f, (double)vrt_f, 0.0),
							map->world_coords[j + i * SIDE]);
			j++;
		}
		i++;
	}
}
