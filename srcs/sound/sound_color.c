/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:55:01 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/17 23:54:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_sound_color(t_sound *sound, t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	if (sound->smode == S_ON)
		while (sound->scfuncs[i].scmode)
		{
			if (sound->scmode == sound->scfuncs[i].scmode)
			{
				sound->scfuncs[i].f(map, active);
				break ;
			}
			i++;
		}
	else if (map->vdstmode == VDST_LIGHT || map->vdstmode == VDST_DEFAULT)
		while (i < map->nb_vtx)
		{
			map->draw[i].color = rgbi_interi_ltd(map->draw[i].color,
					active.bg1, map->viewdist_active,
					(int)lround(map->distancesxz[i]));
			i++;
		}
}
