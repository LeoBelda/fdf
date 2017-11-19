/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 22:55:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*map_to_view(t_list *elem, void *view_mat)
{
	t_list	*new;
	t_vec4	view;

	view = mat4xvec4(sclmat4new(5.0, 5.0, 5.0), *((t_vec4*)(elem->content)));
	view = mat4xvec4(*((t_mat4*)view_mat), view);
	if (!(new = ft_lstnew(&view, sizeof(t_vec4))))
		return (NULL);
	return (new);
}

static void	line_to_screen(t_vec4 a, t_vec4 b, imginf)
{

}

static void	coords_to_img(t_map *map, t_img *imginf)
{
	size_t	x;
	size_t	y;
	t_list	*tmp;

	y = 0;
	tmp = map->to_draw;
	while (y < map->nb_line)
	{
		x = 0;
		while (x < map->nb_col)
		{
			if (x + 1 < nb_col)
				line_to_screen(*(t_vec4*)(tmp->content),
						*(t_vec4*)(tmp->next->content), *imginf);
			if (y + 1 < nb_line)
				line_to_screen(*(t_vec4*)(tmp->content),
						*(t_vec4*)((ft_listat(tmp, map->nb_col))->content),
						*imginf);
			x++;
			tmp = tmp->next;
		}
		y++;
	}
}


		/*
		x = lround(((t_vec4*)(to_draw->content))->x);
		y = lround(((t_vec4*)(to_draw->content))->y);
		intaddr = (int*)&(addr[x * (bpp / 8) + y * size_line]);
		*intaddr = C_CYAN;
		to_draw = to_draw->next;
		*/
}

void		draw(t_env *e)
{
	char	*addr;
	t_mat4	view_mat;

	if (!(e->img->img = mlx_new_image(e->mlx, XWIN, YWIN)))
		error_exit("mlx_new_image failed to deliver");
	e->img->addr = mlx_get_data_addr
					(e->img, &(e->bpp), &(e->size_line), &(e->endian));
	view_mat = calculate_view_mat(e->cam);
	e->map->to_draw = ft_lstmap_param(e->map->vertices, (void*)(&view_mat),
						map_to_screen);
	coords_to_img(e->map, e->img);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0) == -1)
		error_exit("Failed to display image");
	if (mlx_destroy_image(e->mlx, e->img) == -1)
		error_exit("Failed to destroy image");
}
