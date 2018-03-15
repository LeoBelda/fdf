/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/15 15:26:49 by lbelda           ###   ########.fr       */
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

static void		set_buffer(int *addr, t_colors *colors)
{
	size_t	i;

	i = 0;
	while (colors->bfuncs[i].bmode)
	{
		if (colors->bmode == colors->bfuncs[i].bmode)
		{
			send_threads_buf(colors->bfuncs[i].f, addr, colors->active.bg1);
			break ;
		}
		i++;
	}
}

static void		set_vdst(t_sound *sound, t_map *map)
{
	size_t	i;

	i = 0;
	while (map->vdstfuncs[i].vdstmode)
	{
		if (map->vdstmode == map->vdstfuncs[i].vdstmode)
		{
			map->vdstfuncs[i].f(sound, map);
			break ;
		}
		i++;
	}
}

static void		handle_sdl_events(t_env *e)
{
	SDL_Event	event;

	(void)e;
	while (SDL_PollEvent(&event))
	{
		if (iabs(event.caxis.value) <= 5500)
			event.caxis.value = 0;
		if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
			ps3_camroty(e, event.caxis.value);
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
			ps3_camrotx(e, event.caxis.value);
		else if (event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
			ps3_camtrsz(e, event.caxis.value);
		else if (event.cbutton.button == PS3_LEFT_SHOULDER)
			ps3_camrotz(e, (event.cbutton.state ? 1 : 0));
		else if (event.cbutton.button == PS3_RIGHT_SHOULDER)
			ps3_camrotz(e, (event.cbutton.state ? -1 : 0));
	}
}

int				draw(t_env *e)
{
	handle_sdl_events(e);
	set_buffer(e->img->addr, e->colors);
	get_sound_data(e->sound);
	send_threads_m(get_active_world, e->map);
	get_eye_pos(e->matrices);
	get_distances(e->matrices->eye_pos, e->map);
	e->map->middle = get_new_middle(e->map);
	set_vdst(e->sound, e->map);
	set_dst_map(e->map);
	set_sound_map(e->sound, e->map);
	set_matrices(e, e->matrices);
	set_color(e->colors);
	draw_starbox(e->map, e->matrices, e->colors->active, e->img->addr);
	send_threads(vertices_to_proj, e);
	send_threads(proj_to_draw, e);
	set_sound_color(e->sound, e->map, e->colors->active);
	send_threads(draw_to_img, e);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
	return (0);
}
