/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:01:01 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/16 13:02:15 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_clip(t_vec3 elem)
{
	if (elem.x >= 1.0 || elem.x < -1.0
	|| elem.y >= 1.0 || elem.y < -1.0
	|| elem.z >= 1.0 || elem.z < -1.0)
	{
		if (elem.z >= 1.0 || elem.z < -1.0)
			return (2);
		else
			return (1);
	}
	return (0);
}

void		*vertices_to_proj(void *dt)
{
	size_t	i;
	t_vec4	*vertices;
	t_thrd	*d;

	d = (t_thrd*)dt;
	i = d->i;
	vertices = d->e->map->m_world_vtx;
	while (i < d->e->map->nb_vtx)
	{
		d->e->map->proj[i] = mat4xvec4_tovec3(d->e->matrices->f_mat,
											vertices[i]);
		d->e->map->clip[i] = in_clip(d->e->map->proj[i]);
		i += NB_THRD;
	}
	return (NULL);
}

void		*proj_to_draw(void *dt)
{
	size_t	i;
	t_thrd	*d;

	d = (t_thrd*)dt;
	i = d->i;
	while (i < d->e->map->nb_vtx)
	{
		d->e->map->draw[i] = (t_vec2c)
			{ (d->e->map->proj[i].x + 1.0) * X_WIN / 2.0,
			(d->e->map->proj[i].y + 1.0) * Y_WIN / 2.0,
			get_color(d->e->map->min_y, d->e->map->max_y,
						(int)d->e->map->world_vtx[i].y,
						d->e->colors->active),
			d->e->map->distancesxz[i] };
		i += NB_THRD;
	}
	return (NULL);
}
