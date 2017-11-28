/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:36:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 23:31:05 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		key_press_hook(int keycode, void *param)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	kfuncs = ((t_env*)param)->controls->camera;
	i = 0;
	while (kfuncs[i].f)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f((t_env*)param, 1);
		i++;
	}
	return (0);
}

int		key_release_hook(int keycode, void *param)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	kfuncs = ((t_env*)param)->controls->camera;
	i = 0;
	while (kfuncs[i].f)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f((t_env*)param, 0);
		i++;
	}
	return (0);
}
