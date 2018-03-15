/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:36:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/15 16:27:30 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		quit_hook(t_env *e)
{
	if (mlx_destroy_image(e->mlx, e->img->img) == -1)
		error_exit("Failed to destroy image");
	free_all_the_stuff(e);
	getchar();
	exit(0);
}

int		key_hook(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	i = 0;
	kfuncs = e->controls->active;
	while (kfuncs[i].f)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f(e, 1);
		i++;
	}
	return (0);
}

int		key_release_hook(int keycode, t_env *e)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	i = 0;
	kfuncs = e->controls->active;
	while (kfuncs[i].f)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f(e, 0);
		i++;
	}
	return (0);
}
