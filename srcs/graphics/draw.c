/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 13:23:22 by lbelda           ###   ########.fr       */
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
	int	i;

	(void)color;
	i = 0;
	while (i < (XWIN * YWIN))
		rgbcpy(&addr[i++], color);
}

void			draw(t_env *e)
{
	clear_img(e->img->addr, e->colors->active.background);
	set_matrices(e->matrices);
	vertices_to_proj(e->map, e->matrices->f_mat);
	proj_to_draw(e->map, e->colors->active);
	draw_to_img(e->map, e->img);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
}
