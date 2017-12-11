/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_programs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:02:40 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 02:17:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		dst_default_ns(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->mod_vertices[i].z = map->vertices[i].z;
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}

void		dst_default(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
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
			map->target_vtx_z[i] =
				map->vertices[i].z * map->distancesxz[i] / map->viewdist_active;
		else
			map->target_vtx_z[i] = map->vertices[i].z;
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
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
			map->mod_vertices[i].z = map->vertices[i].z *
				map->distancesxz[i] / map->viewdist_active;
		else
			map->mod_vertices[i].z = map->vertices[i].z;
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}
