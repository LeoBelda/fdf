/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 20:31:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		error_exit("");
	if (!(e->win = mlx_new_window(e->mlx, XWIN, YWIN, "FdF")))
		error_exit("");
	if (!(e->img->img = mlx_new_image(e->mlx, XWIN, YWIN)))
		error_exit("mlx_new_image failed to deliver");
	e->img->addr = (int*)mlx_get_data_addr(e->img->img, &(e->img->bpp),
						&(e->img->size_line), &(e->img->endian));
	mlx_do_key_autorepeatoff(e->mlx);
	mlx_key_hook(e->win, key_hook, (void*)e);
	mlx_mouse_hook(e->win, mouse_hook, (void*)e);
	mlx_hook(e->win, 2, 0, key_press_hook, (void*)e);
	mlx_hook(e->win, 3, 0, key_release_hook, (void*)e);
	mlx_expose_hook(e->win, expose_hook, (void*)e);
	mlx_loop_hook(e->mlx, draw, (void*)e);
}

static void	alloc_env(t_env *e)
{
	if (!(e->map = ft_memalloc(sizeof(t_map))))
		error_exit("");
	if (!(e->img = ft_memalloc(sizeof(t_img))))
		error_exit("");
	if (!(e->matrices = ft_memalloc(sizeof(t_matrices))))
		error_exit("");
	if (!(e->colors = ft_memalloc(sizeof(t_colors))))
		error_exit("");
	if (!(e->controls = ft_memalloc(sizeof(t_controls))))
		error_exit("");
	if (!(e->overlay = ft_memalloc(sizeof(t_overlay))))
		error_exit("");
	if (!(e->sound = ft_memalloc(sizeof(t_sound))))
		error_exit("");
}

void		fdf(char *file, char *audio)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("");
	alloc_env(e);
	parse_map(e->map, file);
	init_geometry(e->matrices, e->map);
	init_colors(e->colors);
	init_controls(e);
	init_overlay(e->overlay);
	if (audio)
		init_sound(e->sound, audio);
	e->mode = M_GRD;
	init_mlx(e);
	mlx_loop(e->mlx);
}
