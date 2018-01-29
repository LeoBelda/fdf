/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sr_programs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:40:42 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 12:15:38 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_mod_z(float act, float tar, float atk, float rls)
{
	if (fabs(tar) > fabs(act))
		return (act = act + (tar >= 0 ? ((tar - act) / atk) :
										((tar - act) / atk)));
	else
		return (act = act + (act >= 0 ? -act / rls : -act / rls));
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
	if (!map->az_targut)
		while (i < map->nb_vtx)
		{
			map->target_vtx_y[i] = map->world_vtx[i].y * spec->low_band * 2;
			map->m_world_vtx[i].y = get_mod_z(map->m_world_vtx[i].y,
											map->target_vtx_y[i], 5.0, 10.0);
			i++;
		}
	else
		while (i < map->nb_vtx)
		{
			map->target_vtx_y[i] = map->target_vtx_y[i] * spec->low_band * 2;
			map->m_world_vtx[i].y = get_mod_z(map->world_vtx[i].y,
											map->target_vtx_y[i], 5.0, 10.0);
			i++;
		}
}

void			sr_total_alti(t_spec *spec, t_map *map)
{
	size_t	i;

	i = 0;
	if (!map->az_targut)
		while (i < map->nb_vtx)
		{
			map->target_vtx_y[i] = map->world_vtx[i].y * spec->total * 4;
			map->m_world_vtx[i].y = get_mod_z(map->m_world_vtx[i].y,
										map->target_vtx_y[i], 100.0, 120.0);
			i++;
		}
	else
		while (i < map->nb_vtx)
		{
			map->target_vtx_y[i] = map->target_vtx_y[i] * spec->total * 4;
			map->m_world_vtx[i].y = get_mod_z(map->m_world_vtx[i].y,
										map->target_vtx_y[i], 100.0, 120.0);
			i++;
		}
}
