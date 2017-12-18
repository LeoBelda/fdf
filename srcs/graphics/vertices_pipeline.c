/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:44:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 20:18:46 by lbelda           ###   ########.fr       */
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
			get_color(d->e->map->min_z, d->e->map->max_z,
						(int)d->e->map->world_vtx[i].y, d->e->colors->active),
			d->e->map->distancesxz[i] };
		i += NB_THRD;
	}
	return (NULL);
}

void		draw_line(t_map *map, int *addr, size_t i, size_t j)
{
	if ((!map->clip[i] || !map->clip[j]))
	{
		if (!map->clip[i] && !map->clip[j])
			bresenham(map->draw[i], map->draw[j], addr);
		else if (map->clip[i] != 2 && map->clip[j] != 2)
			bresenham_clip(map->draw[i], map->draw[j], addr);
	}
}

void		*draw_to_img(void *dt)
{
	size_t	x;
	size_t	y;
	size_t	i;
	t_thrd	*d;

	d = (t_thrd*)dt;
	i = d->i;
	y = d->i / d->e->map->nb_col;
	while (y < d->e->map->nb_line)
	{
		x = i % d->e->map->nb_col;
		while (x < d->e->map->nb_col)
		{
			if (x + 1 < d->e->map->nb_col)
				draw_line(d->e->map, d->e->img->addr,
									i, i + 1);
			if (y + 1 < d->e->map->nb_line)
				draw_line(d->e->map, d->e->img->addr,
									i, i + d->e->map->nb_col);
			i += NB_THRD;
			x += NB_THRD;
		}
		y++;
	}
	return (NULL);
}
