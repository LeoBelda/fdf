/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 19:58:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*vertex_to_view(t_list *elem, void *view_mat)
{
	t_list	*new;
	t_vec4	view;

	view = mat4xvec4(*((t_mat4*)view_mat), *((t_vec4*)(elem->content)));
	if (!(new = ft_lstnew(&view, sizeof(t_vec4))))
		return (NULL);
	return (new);
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
			if (x + 1 < map->nb_col)
				draw_line(*(t_vec4*)(tmp->content),
						*(t_vec4*)(tmp->next->content), *imginf);
			if (y + 1 < map->nb_line)
				draw_line(*(t_vec4*)(tmp->content),
						*(t_vec4*)((ft_lstat(tmp, map->nb_col))->content),
						*imginf);
			x++;
			tmp = tmp->next;
		}
		y++;
	}
}

void		draw(t_env *e)
{
	if (!(e->img->img = mlx_new_image(e->mlx, XWIN, YWIN)))
		error_exit("mlx_new_image failed to deliver");
	e->img->addr = mlx_get_data_addr(e->img->img, &(e->img->bpp),
						&(e->img->size_line), &(e->img->endian));
	set_matrices(e->matrices);
	e->map->to_draw = ft_lstmap_param(e->map->vertices,
								(void*)&e->matrices->f_mat, vertex_to_view);
	coords_to_img(e->map, e->img);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	if (mlx_destroy_image(e->mlx, e->img->img) == -1)
		error_exit("Failed to destroy image");
}
