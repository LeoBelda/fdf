/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:22:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 17:42:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*map_to_screen(t_list *elem, void *view_mat)
{
	t_list	*new;
	t_vec4	view;

	/* ci-git SEGFAULT */
	view = mat4xvec4(*((t_mat4*)view_mat), *((t_vec4*)(elem->content)));
	ft_putendl("Ye");
	if (!(new = ft_lstnew(&view, sizeof(t_vec4))))
		return (NULL);
	return (new);
}

void	draw(t_env *e)
{
	void	*img;
	char	*addr;
	t_mat4	view_mat;

	img = mlx_new_image(e->mlx, XWIN, YWIN);
	addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &(e->endian));
	view_mat = calculate_view_mat(e->cam);
	e->map->to_draw = ft_lstmap_param(e->map->vertices, (void*)(&view_mat),
						map_to_screen);
	print_parsed_map(e->map->to_draw);
	sleep(10);

	if (mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0) == -1)
		error_exit("Failed to display image");
	if (mlx_destroy_image(e->mlx, e->img) == -1)
		error_exit("Failed to destroy image");
}
