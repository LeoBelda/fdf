/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_programs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:56:16 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 02:52:00 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			sc_default(t_map *map, t_colorset active)
{
	(void)map;
	(void)active;
}

void			sc_total_vision(t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->draw[i].color = rgbi_interi_ltd(map->draw[i].color,
				active.background1, map->viewdist_active,
				(int)lround(map->distancesxz[i]));
		i++;
	}
}

void			sc_total_unvision(t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->draw[i].color = rgbi_interi(map->draw[i].color, active.background1,
				200, (int)lround(map->distancesxy[i]));
		map->draw[i].color = rgbi_interi(active.background1, map->draw[i].color,
				map->viewdist_active, (int)lround(map->distancesxz[i]));
		i++;
	}
}
