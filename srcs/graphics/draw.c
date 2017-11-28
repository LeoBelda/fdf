/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 21:42:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	get_color(double min_z, double max_z, double z, t_colorset active)
{
	return (rgb_interi(active.bottom, active.top, (int)lround(max_z - min_z),
												(int)(lround(z - min_z))));
}



static void		clear_img(int *addr, t_rgb color)
{
	ft_intset(addr, rgb_to_int(color), XWIN * YWIN);
}

static void		set_color(t_colors *colors)
{
	size_t		j;
	t_rgb		*handle_act;
	t_rgb		*handle_tar;
	t_rgb		*handle_from;

	if (!ft_memcmp((void*)&(colors->active),
				   (void*)&(colors->target), sizeof(t_colorset)))
	{
		colors->progress = 0;
		return ;
	}
	j = 0;
	handle_act = &colors->active.text;
	handle_tar = &colors->target.text;
	handle_from = &colors->from.text;
	while (&(handle_tar[j]) <= &colors->target.top)
	{
		handle_act[j] = rgb_interi(handle_from[j], handle_tar[j],
									100, colors->progress);
		j++;
	}
	colors->progress++;
}

void			draw(t_env *e)
{
	clear_img(e->img->addr, e->colors->active.background);
	set_matrices(e->matrices);
	set_color(e->colors);
	vertices_to_proj(e->map, e->matrices->f_mat);
	proj_to_draw(e->map, e->colors->active);
	draw_to_img(e->map, e->img);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
}
