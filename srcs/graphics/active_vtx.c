/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_vtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 05:53:59 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 10:26:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define TOT_X (int)d->map->nb_col_glb
#define TOT_Y (int)d->map->nb_line_glb

t_vec2r		get_new_middle(t_map *map)
{
	int		rel_x;
	int		rel_y;

	rel_x = (int)map->closest_vtx_i % SIDE - SIDE / 2;
	rel_y = (int)map->closest_vtx_i / SIDE - SIDE / 2;
	return ((t_vec2r) { map->middle.x + rel_x, map->middle.y + rel_y });
}

static int	get_trs(int i, int middle, int max)
{
	int	fct;

	if (middle + (i - SIDE / 2) > 0 || (middle + (i - SIDE / 2)) % max == 0)
		fct = (middle + (i - SIDE / 2)) / max;
	else
		fct = ((middle + (i - SIDE / 2)) / max) - 1;
	return (fct);
}

void		*get_active_world(void *dt)
{
	int		i;
	int		j;
	t_thrdm	*d;

	d = (t_thrdm*)dt;
	i = -1;
	if (d->map->infmode == INF_OFF)
		return (NULL);
	while (++i < SIDE)
	{
		j = d->i - NB_THRD;
		while ((j += NB_THRD) < SIDE)
		{
			d->map->world_vtx[j + i * SIDE] = d->map->world_coords_glb
				[imod(((d->map->middle.x + (j - SIDE / 2))), TOT_X)
				+ imod((d->map->middle.y + (i - SIDE / 2)), TOT_Y) * TOT_X];
			d->map->world_vtx[j + i * SIDE] = mat4xvec4(trsmat4new(
			(double)(get_trs(j, d->map->middle.x, TOT_X) * TOT_X * X_SCALE),
			0.0,
			(double)(get_trs(i, d->map->middle.y, TOT_Y) * TOT_Y * Z_SCALE)),
							d->map->world_vtx[j + i * SIDE]);
		}
	}
	return (NULL);
}
