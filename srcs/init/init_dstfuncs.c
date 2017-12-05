/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_distfuncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:50:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 23:50:01 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dstfuncs(t_map *map)
{
	if (!(map->dstfuncs = ft_memalloc(sizeof(t_dstfuncs) * 3)))
		error_exit("");
	(map->dstfuncs)[0] = (t_dstfuncs) { dst_default, DST_DEFAULT };
	(map->dstfuncs)[1] = (t_dstfuncs) { dst_around_flat, DST_AROUND_FLAT };
	(map->dstfuncs)[2] = (t_dstfuncs) { NULL, 0 };
}

void	set_vdstfuncs(t_map *map)
{
	if (!(map->vdstfuncs = ft_memalloc(sizeof(t_vdstfuncs) * 3)))
		error_exit("");
	(map->vdstfuncs)[0] = (t_vdstfuncs) { vdst_default, VDST_DEFAULT };
	(map->vdstfuncs)[1] = (t_vdstfuncs) { vdst_sound_total, VDST_SOUND_TOTAL };
	(map->vdstfuncs)[2] = (t_vdstfuncs) { NULL, 0 };
}
