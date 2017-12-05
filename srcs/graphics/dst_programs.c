/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_programs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:02:40 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 22:29:27 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		dst_default(t_map *map)
{
	(void)map;
}

void		dst_around_flat(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		if (map->distancesxz[i] < map->viewdist_active)
			map->target_vtx_z[i] = map->vertices[i].z * map->distancesxz[i] / map->viewdist_active;
		else
			map->target_vtx_z[i] = map->vertices[i].z;
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}
