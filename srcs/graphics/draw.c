/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 23:22:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		clear_img(int *addr, int color)
{
	long int	longcolor;

	ft_intset(&longcolor, color, 2);
	ft_lintset(addr, longcolor, XWIN * YWIN / 2);
}

int			draw(t_env *e)
{
	clear_img(e->img->addr, e->colors->active.background);
	e->matrices->eye_pos = get_eye_pos(e->matrices->views->active);
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
