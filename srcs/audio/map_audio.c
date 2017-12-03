/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_audio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:10:56 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 16:25:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_mod_z(float act, float tar)
{
	if (fabs(tar) > fabs(act))
		return (act = act + (tar >= 0 ? ((tar - act) / 5.0) : ((tar - act) / 5.0)));
	else
		return (act = act + (tar >= 0 ? -((tar + act) / 10.0) : -((tar + act) / 10.0)));
}

void			map_audio(t_spec *spec, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->target_vtx_z[i] = map->vertices[i].z * spec->low_band;
		map->mod_vertices[i].z = get_mod_z(map->mod_vertices[i].z,
											map->target_vtx_z[i]);
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}
