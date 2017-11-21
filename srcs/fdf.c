/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 22:18:59 by lbelda           ###   ########.fr       */
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

static void	malloc_env(t_env *e)
{
	if (!(e->map = ft_memalloc(sizeof(t_map))))
		error_exit("");
	if (!(e->img = ft_memalloc(sizeof(t_img))))
		error_exit("");
	if (!(e->cam = ft_memalloc(sizeof(t_cam))))
		error_exit("");
	if (!(e->modmat = ft_memalloc(sizeof(t_modmat))))
		error_exit("");
}

static void	set_init_state(t_cam *cam, t_modmat *modmat)
{
	modmat->rx = 33.0;
	modmat->ry = -33.0;
	modmat->rz = 10.0;
	modmat->tx = 800.0;
	modmat->ty = 300.0;
	modmat->tz = 0.0;
	modmat->s = 5.0;
	cam->eye = vec4new(0.0, 0.0, 50.0, 0.0);
	cam->target = vec4new(0.0, 0.0, 0.0, 0.0);
	cam->up = vec4new(0.0, 1.0, 0.0, 0.0);
}

void		fdf(char *map)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("");
	malloc_env(e);
	parse_map(e->map, map);
	set_init_state(e->cam, e->modmat);
	init_mlx(e);
	mlx_loop(e->mlx);
}
