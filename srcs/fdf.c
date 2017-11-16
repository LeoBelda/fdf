/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/16 19:05:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		error_exit();
	if (!(e->win = mlx_new_window(e->mlx, XWIN, YWIN, "FdF")))
		error_exit();
	mlx_key_hook(e->win, key_hook, (void*)e);
}

void		fdf(void)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit();
	init_env(e);
	mlx_loop(e->mlx);
}
