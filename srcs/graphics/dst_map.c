/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:05:16 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 14:41:33 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dst_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->dstfuncs[i].dstmode != DST_LAST)
	{
		if (map->dstmode == map->dstfuncs[i].dstmode)
		{
			map->dstfuncs[i].f(map);
			break ;
		}
		i++;
	}
}

void	get_distances(t_vec4 eye_pos, t_map *map)
{
	size_t	i;
	double	min;

	i = 0;
	map->closest_vtx_i = 0;
	min = 6000.0;
	while (i < map->nb_vtx)
	{
		map->distancesxy[i] = vec4_xy_distance(eye_pos, map->world_vtx[i]);
		if ((map->distancesxz[i] =
				vec4_xz_distance(eye_pos, map->world_vtx[i])) <= min)
		{
			min = map->distancesxz[i];
			map->closest_vtx_i = i;
		}
		i++;
	}
}
