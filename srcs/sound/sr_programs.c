/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sr_programs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:40:42 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 21:44:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_mod_z(float act, float tar, float atk, float rls)
{
	if (fabs(tar) > fabs(act))
		return (act = act + (tar >= 0 ? ((tar - act) / atk) : ((tar - act) / atk)));
	else
		return (act = act + (tar >= 0 ? -((tar + act) / rls) : -((tar + act) / rls)));
}

void			sr_default(t_spec *spec, t_map *map)
{
	size_t	i;

	(void)spec;
	(void)map;
	(void)i;
}

void			sr_bass_alti(t_spec *spec, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->target_vtx_z[i] = map->mod_vertices[i].z * spec->low_band * 2;
		map->mod_vertices[i].z = get_mod_z(map->mod_vertices[i].z,
											map->target_vtx_z[i], 5.0, 10.0);
		map->mod_vertices[i].y = map->mod_vertices[i].y;
		map->mod_vertices[i].x = map->mod_vertices[i].x;
		map->mod_vertices[i].w = map->mod_vertices[i].w;
		i++;
	}
}

void			sr_total_alti(t_spec *spec, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->target_vtx_z[i] = map->vertices[i].z * spec->total * 8;
		map->mod_vertices[i].z = get_mod_z(map->mod_vertices[i].z,
											map->target_vtx_z[i], 100.0, 120.0);
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}
