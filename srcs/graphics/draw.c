/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 21:42:53 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_color(t_colors *colors)
{
	size_t	i;

	i = 0;
	while (colors->cfuncs[i].cmode)
	{
		if (colors->cmode == colors->cfuncs[i].cmode)
		{
			colors->cfuncs[i].f(colors);
			break ;
		}
		i++;
	}
}

static void		clear_img(int *addr, t_colorset colorset)
{
	plain_background(addr, colorset.background1);
}

static void		get_distances(t_vec4 eye_pos, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vtx)
	{
		map->distances[i] = vec4_xy_distance(eye_pos, map->world_coords[i]);
		i++;
	}
}

int				draw(t_env *e)
{
	if (e->colors->bufmode == B_DEFAULT)
		clear_img(e->img->addr, e->colors->active);
	get_audio_data(e->sound);
	audio_map(e->sound->data->p_spec, e->map);
	e->matrices->eye_pos = get_eye_pos(e->matrices->views->active);
	get_distances(e->matrices->eye_pos, e->map);
	set_matrices(e->matrices);
	set_color(e->colors);
	vertices_to_proj(e->map, e->matrices->f_mat);
	proj_to_draw(e->map, e->colors->active);
	audio_color(e->sound->data->p_spec, e->map, e->colors->active);
	draw_to_img(e->map, e->img->addr);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
	return (0);
}
