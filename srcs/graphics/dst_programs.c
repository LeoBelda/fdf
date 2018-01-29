/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_programs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:02:40 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 12:12:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		dst_default_ns(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->m_world_vtx[i].x = map->world_vtx[i].x;
		map->m_world_vtx[i].y = map->world_vtx[i].y;
		map->m_world_vtx[i].z = map->world_vtx[i].z;
		map->m_world_vtx[i].w = map->world_vtx[i].w;
		i++;
	}
}

void		dst_default(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->m_world_vtx[i].z = map->world_vtx[i].z;
		map->m_world_vtx[i].x = map->world_vtx[i].x;
		map->m_world_vtx[i].w = map->world_vtx[i].w;
		i++;
	}
}

void		dst_around_flat(t_map *map)
{
	size_t	i;

	i = 0;
	map->az_targut = 1;
	while (i < map->nb_vtx)
	{
		if (map->distancesxz[i] < map->viewdist_active)
			map->target_vtx_y[i] =
				map->world_vtx[i].y * map->distancesxz[i]
						/ map->viewdist_active;
		else
			map->target_vtx_y[i] = map->world_vtx[i].y;
		map->m_world_vtx[i].z = map->world_vtx[i].z;
		map->m_world_vtx[i].x = map->world_vtx[i].x;
		map->m_world_vtx[i].w = map->world_vtx[i].w;
		i++;
	}
}

void		dst_around_flat_ns(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		if (map->distancesxz[i] < map->viewdist_active)
			map->m_world_vtx[i].y = map->world_vtx[i].y *
				map->distancesxz[i] / map->viewdist_active;
		else
			map->m_world_vtx[i].y = map->world_vtx[i].y;
		map->m_world_vtx[i].z = map->world_vtx[i].z;
		map->m_world_vtx[i].x = map->world_vtx[i].x;
		map->m_world_vtx[i].w = map->world_vtx[i].w;
		i++;
	}
}
