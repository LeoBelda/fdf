/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_audio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:10:56 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/04 17:33:18 by lbelda           ###   ########.fr       */
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

static int		get_mod_dist(int act, int tar)
{
	if (tar > act)
		return (act += (tar - act) / 8.0);
	else
		return (act -= ((act - tar) / 10.0));
}

void			audio_color(t_spec *spec, t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	(void)spec;
	map->viewdist_target = (int)lround(1000.0 * (spec->low_band + 0.15));
	map->viewdist_active = get_mod_dist(map->viewdist_active,
										map->viewdist_target);
	while (i < map->nb_vtx)
	{
		map->draw[i].color = rgbi_interi(map->draw[i].color, active.background1,
				map->viewdist_active, (int)lround(map->distancesxz[i]));
		map->draw[i].color = rgbi_interi(map->draw[i].color, active.background1,
				200, (int)lround(map->distancesxy[i]));
		i++;
	}
}

void			audio_map(t_spec *spec, t_map *map)
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
