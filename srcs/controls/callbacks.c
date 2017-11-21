/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:36:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 22:11:02 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(void *param)
{
	draw((t_env*)param);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == K_ESC)
		exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	expose_hook(void *param)
{
	(void)param;
	return (0);
}
