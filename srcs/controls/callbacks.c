/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:36:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 15:04:04 by lbelda           ###   ########.fr       */
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

int		key_press_hook(int keycode, t_env *e)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	kfuncs = (e->mode == M_SKY ? e->controls->sky : e->controls->grd);
	i = 0;
	while (kfuncs[i].f && e->matrices->views->switching == 0)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f(e, 1);
		i++;
	}
	ft_putnbr(keycode);
	ft_putendl("");
	return (0);
}

int		key_release_hook(int keycode, t_env *e)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	kfuncs = (e->mode == M_SKY ? e->controls->sky : e->controls->grd);
	i = 0;
	while (kfuncs[i].f && e->matrices->views->switching == 0)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f(e, 0);
		i++;
	}
	return (0);
}
