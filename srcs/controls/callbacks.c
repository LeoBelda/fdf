/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:36:46 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 13:41:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	size_t		i;
	t_kfuncs	*kfuncs;

	kfuncs = (((t_env*)param)->controls->mode ?
			((t_env*)param)->controls->modelmode :
			((t_env*)param)->controls->cammode);
	i = 0;
	while (kfuncs[i].f)
	{
		if (keycode == kfuncs[i].keycode)
			kfuncs[i].f((t_env*)param);
		i++;
	}
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

static void	set_kfuncs_model(t_controls *controls)
{
	if (!(controls->modelmode = ft_memalloc(sizeof(t_kfuncs) * 11)))
		error_exit("");
	(controls->modelmode)[0] = (t_kfuncs) { k_exit, K_ESC };
	(controls->modelmode)[1] = (t_kfuncs) { k_trsleft, K_LEFT };
	(controls->modelmode)[2] = (t_kfuncs) { k_trsright, K_RIGHT };
	(controls->modelmode)[3] = (t_kfuncs) { k_trsup, K_UP };
	(controls->modelmode)[4] = (t_kfuncs) { k_trsdown, K_DOWN };
	(controls->modelmode)[5] = (t_kfuncs) { k_rotx, K_W };
	(controls->modelmode)[6] = (t_kfuncs) { k_rotrx, K_S };
	(controls->modelmode)[7] = (t_kfuncs) { k_roty, K_A };
	(controls->modelmode)[8] = (t_kfuncs) { k_rotry, K_D };
	(controls->modelmode)[9] = (t_kfuncs) { k_chmode, K_P };
	(controls->modelmode)[10] = (t_kfuncs) { NULL, 0 };
}

static void	set_kfuncs_camera(t_controls *controls)
{
	if (!(controls->cammode = ft_memalloc(sizeof(t_kfuncs) * 11)))
		error_exit("");
	(controls->cammode)[0] = (t_kfuncs) { k_exit, K_ESC };
	(controls->cammode)[1] = (t_kfuncs) { k_rotcamy, K_RIGHT };
	(controls->cammode)[2] = (t_kfuncs) { k_rotcamry, K_LEFT };
	(controls->cammode)[3] = (t_kfuncs) { k_rotcamx, K_UP };
	(controls->cammode)[4] = (t_kfuncs) { k_rotcamrx, K_DOWN };
	(controls->cammode)[5] = (t_kfuncs) { k_trscamx, K_A };
	(controls->cammode)[6] = (t_kfuncs) { k_trscamrx, K_D };
	(controls->cammode)[7] = (t_kfuncs) { k_trscamz, K_W };
	(controls->cammode)[8] = (t_kfuncs) { k_trscamrz, K_S };
	(controls->cammode)[9] = (t_kfuncs) { k_chmode, K_P };
	(controls->cammode)[10] = (t_kfuncs) { NULL, 0 };
}

void	set_controls(t_controls *controls)
{
	set_kfuncs_model(controls);
	set_kfuncs_camera(controls);
	controls->mode = 1;
}
