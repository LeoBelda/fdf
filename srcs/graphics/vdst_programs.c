/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdst_programs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:46:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 20:36:44 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_mod_dist(int act, int tar, int atk, int rls)
{
	if (tar > act)
		return (act += (tar - act) / atk);
	else
		return (act -= ((act - tar) / rls));
}

void	vdst_default(t_spec *spec, t_map *map)
{
	(void)spec;
	map->viewdist_active = 1000;
	map->viewdist_target = 1000;
}

void	vdst_sound_total(t_spec *spec, t_map *map)
{
	map->viewdist_target = (int)lround(2000.0 * (spec->total + 0.10));
	map->viewdist_active = get_mod_dist(map->viewdist_active,
										map->viewdist_target, 16, 20);
}
