/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 20:18:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		error_exit("");
	if (!(e->win = mlx_new_window(e->mlx, XWIN, YWIN, "FdF")))
		error_exit("");
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
	if (!(e->matrices->initst = ft_memalloc(sizeof(t_modmat))))
		error_exit("");
}

static void	set_init_state(t_matrices *matrices)
{
	matrices->initst->rx = 33.0;
	matrices->initst->ry = -33.0;
	matrices->initst->rz = 10.0;
	matrices->initst->tx = 700.0;
	matrices->initst->ty = 300.0;
	matrices->initst->tz = 0.0;
	matrices->initst->s = 5.0;
	matrices->cam->eye = vec4new(0.0, 0.0, 50.0, 0.0);
	matrices->cam->target = vec4new(0.0, 0.0, 0.0, 0.0);
	matrices->cam->up = vec4new(0.0, 1.0, 0.0, 0.0);
}

void		fdf(char *map)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("");
	alloc_env(e);
	parse_map(e->map, map);
	set_init_state(e->matrices);
	init_mlx(e);
	mlx_loop(e->mlx);
}
