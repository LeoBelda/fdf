/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdst_programs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:46:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 06:44:09 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_mod_dist(int act, int tar, int atk, int rls)
{
	if (tar > act)
		return (act += (tar - act) / atk);
	else
		return (act -= ((act - tar) / rls));
}

void		vdst_default(t_sound *sound, t_map *map)
{
	(void)sound;
	map->viewdist_active = 2000;
	map->viewdist_target = 2000;
}

void		vdst_light(t_sound *sound, t_map *map)
{
	(void)sound;
	map->viewdist_active = 800;
	map->viewdist_target = 800;
}


void		vdst_sound_total(t_sound *sound, t_map *map)
{
	map->viewdist_target = (int)lround(2000.0 *
							(sound->data->p_spec->total + 0.10));
	map->viewdist_active = get_mod_dist(map->viewdist_active,
										map->viewdist_target, 16, 20);
}
