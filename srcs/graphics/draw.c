/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 23:02:44 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		vertices_to_proj(t_map *map, t_mat4 f_mat)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vertices)
	{
		map->proj_array[i] = mat4xvec4(f_mat, map->vertices_array[i]);
		i++;
	}
}

static t_rgb	get_color(double min_z, double max_z, double z, t_colors colors)
{
	return (rgb_interi(colors.bottom, colors.top, (int)lround(max_z - min_z),
												(int)(lround(z))));
}

static void		proj_to_draw(t_map *map, t_colors *colors)
{
	size_t	i;

	i = 0;
	while (i < map->nb_vertices)
	{
		map->draw_array[i] = (t_vec2c)
							{ (map->proj_array[i].x + 1.0) * X_WIN / 2.0,
							  (map->proj_array[i].y + 1.0) * Y_WIN / 2.0,
							  get_color(map->min_z, map->max_z,
										map->vertices_array[i].z, *colors)};
		i++;
	}
}

static int		detect_clip(t_vec4 elem)
{
	if (elem.x > 1.0 || elem.x < -1.0
	 || elem.y > 1.0 || elem.y < -1.0 
	 || elem.z > 1.0 || elem.z < -1.0)
		return (0);
	else
		return (1);
}

static void		coords_to_img(t_map *map, t_img *imginf)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (y < map->nb_line)
	{
		x = 0;
		while (x < map->nb_col)
		{
			if (detect_clip(map->proj_array[i]))
			{
				if (x + 1 < map->nb_col && detect_clip(map->proj_array[i + 1]))
					draw_line(map->draw_array[i],
								map->draw_array[i + 1], *imginf);
				if (y + 1 < map->nb_line &&
				detect_clip(map->proj_array[i + map->nb_col]))
					draw_line(map->draw_array[i], 
								map->draw_array[i + map->nb_col], *imginf);
			}
			i++;
			x++;
		}
		y++;
	}
}

static void		clear_img(int *addr, t_rgb color)
{
	int	i;

	(void)color;
	i = 0;
	while (i < (XWIN * YWIN))
		addr[i++] = 0x00000000;
}

void			draw(t_env *e)
{
	clear_img(e->img->addr, e->colors->background);
	set_matrices(e->matrices);
	vertices_to_proj(e->map, e->matrices->f_mat);
	proj_to_draw(e->map, e->colors);
	coords_to_img(e->map, e->img);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
}
