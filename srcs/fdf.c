/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/17 18:51:53 by lbelda           ###   ########.fr       */
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

void		fdf(char *map)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("");
	init_mlx(e);
	parse_map(&(e->map), map);
	position_camera(&(e->cam));
	print_parsed_map(e->map);
	mlx_loop(e->mlx);
}
