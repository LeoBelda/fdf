/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sr_programs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:40:42 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 10:22:43 by lbelda           ###   ########.fr       */
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
			map->target_vtx_z[i] = map->world_vtx[i].z * spec->low_band * 2;
			map->m_world_vtx[i].z = get_mod_z(map->m_world_vtx[i].z,
											map->target_vtx_z[i], 5.0, 10.0);
			i++;
		}
	else
		while (i < map->nb_vtx)
		{
			map->target_vtx_z[i] = map->target_vtx_z[i] * spec->low_band * 2;
			map->m_world_vtx[i].z = get_mod_z(map->world_vtx[i].z,
											map->target_vtx_z[i], 5.0, 10.0);
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
			map->target_vtx_z[i] = map->world_vtx[i].z * spec->total * 4;
			map->m_world_vtx[i].z = get_mod_z(map->m_world_vtx[i].z,
										map->target_vtx_z[i], 100.0, 120.0);
			i++;
		}
	else
		while (i < map->nb_vtx)
		{
			map->target_vtx_z[i] = map->target_vtx_z[i] * spec->total * 4;
			map->m_world_vtx[i].z = get_mod_z(map->m_world_vtx[i].z,
										map->target_vtx_z[i], 100.0, 120.0);
			i++;
		}
}
