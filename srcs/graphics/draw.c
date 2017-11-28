/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 18:02:06 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(int min_z, int max_z, int z, t_colorset active)
{
	return (rgbi_interi(active.bottom, active.top, max_z - min_z,
												z - min_z));
}

static void		clear_img(int *addr, int color)
{
	ft_lintset(addr, (long int)color, (XWIN * YWIN) / 2);
}

static void		set_color(t_colors *colors)
{
	size_t	j;
	int		*handle_act;
	int		*handle_tar;
	int		*handle_from;

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
		handle_act[j] = rgbi_interi(handle_from[j], handle_tar[j],
									100, colors->progress);
		j++;
	}
	colors->progress++;
}

int			draw(t_env *e)
{
	clear_img(e->img->addr, e->colors->active.background);
	set_matrices(e->matrices);
	set_color(e->colors);
	vertices_to_proj(e->map, e->matrices->f_mat);
	proj_to_draw(e->map, e->colors->active);
	draw_to_img(e->map, e->img->addr);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
	return (0);
}
