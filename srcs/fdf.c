/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 23:45:05 by lbelda           ###   ########.fr       */
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
	mlx_key_hook(e->win, key_hook, (void*)e);
	mlx_mouse_hook(e->win, mouse_hook, (void*)e);
	mlx_expose_hook(e->win, expose_hook, (void*)e);
	mlx_loop_hook(e->mlx, loop_hook, (void*)e);
}

static void	alloc_env(t_env *e)
{
	if (!(e->map = ft_memalloc(sizeof(t_map))))
		error_exit("");
	if (!(e->img = ft_memalloc(sizeof(t_img))))
		error_exit("");
	if (!(e->matrices = ft_memalloc(sizeof(t_matrices))))
		error_exit("");
	if (!(e->matrices->cam = ft_memalloc(sizeof(t_cam))))
		error_exit("");
	if (!(e->colors = ft_memalloc(sizeof(t_colors))))
		error_exit("");
	if (!(e->controls = ft_memalloc(sizeof(t_controls))))
		error_exit("");
}

static void	set_init_matrices(t_matrices *matrices)
{
	matrices->initst.rx = 0.0;
	matrices->initst.ry = 0.0;
	matrices->initst.rz = 0.0;
	matrices->initst.tx = 0.0;
	matrices->initst.ty = 0.0;
	matrices->initst.tz = 0.0;
	matrices->initst.s = 2.0;
	matrices->camst.rx = 0.0;
	matrices->camst.ry = 0.0;
	matrices->camst.rz = 0.0;
	matrices->camst.tx = 0.0;
	matrices->camst.ty = 0.0;
	matrices->camst.tz = 500.0;
	matrices->cam->target = mat4xvec4(trsmat4new(0.0, 0.0, 0.0),
									vec4new(0.0, 0.0, 0.0, 1.0));
	matrices->cam->up = vec4new(0.0, 1.0, 0.0, 0.0);
	matrices->ortho_proj = orthomat4new(frustrumnew(600.0, 337.5, 20000.0, -20000.0));
	matrices->pers_proj = persmat4new(100.0, 2000.0, 0.0);
}

static void	set_colors(t_colors *colors)
{
	colors->background = C_BLA;
	colors->text = C_WHI;
	colors->bottom = C_WHI;
	colors->top = C_RED;
}

void		fdf(char *file)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("");
	alloc_env(e);
	parse_map(e->map, file);
	set_init_matrices(e->matrices);
	set_colors(e->colors);
	set_controls(e->controls);
	init_mlx(e);
	ft_putendl("wtf");
	mlx_loop(e->mlx);
}
