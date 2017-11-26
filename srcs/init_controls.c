/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:15:02 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 17:29:15 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_kfuncs(t_controls *controls)
{
	if (!(controls->camera = ft_memalloc(sizeof(t_kfuncs) * 10)))
		error_exit("");
	(controls->camera)[0] = (t_kfuncs) { k_rotcamz, K_LEFT };
	(controls->camera)[1] = (t_kfuncs) { k_rotcamrz, K_RIGHT };
	(controls->camera)[2] = (t_kfuncs) { k_rotcamrx, K_UP };
	(controls->camera)[3] = (t_kfuncs) { k_rotcamx, K_DOWN };
	(controls->camera)[4] = (t_kfuncs) { k_trscamz, K_W };
	(controls->camera)[5] = (t_kfuncs) { k_trscamrz, K_S };
	(controls->camera)[6] = (t_kfuncs) { k_rotcamry, K_A };
	(controls->camera)[7] = (t_kfuncs) { k_rotcamy, K_D };
	(controls->camera)[8] = (t_kfuncs) { k_exit, K_ESC };
	(controls->camera)[9] = (t_kfuncs) { NULL, 0 };
}

/*
static void	set_kfuncs_release(t_controls *controls)
{
	if (!(controls->release = ft_memalloc(sizeof(t_kfuncs) * 10)))
		error_exit("");
	(controls->release)[0] = (t_kfuncs) { k_exit, K_ESC };
	(controls->release)[1] = (t_kfuncs) { k_rotcamry, K_LEFT };
	(controls->release)[2] = (t_kfuncs) { k_rotcamy, K_RIGHT };
	(controls->release)[3] = (t_kfuncs) { k_rotcamx, K_UP };
	(controls->release)[4] = (t_kfuncs) { k_rotcamrx, K_DOWN };
	(controls->release)[5] = (t_kfuncs) { k_trscamx, K_A };
	(controls->release)[6] = (t_kfuncs) { k_trscamrx, K_D };
	(controls->release)[7] = (t_kfuncs) { k_trscamz, K_W };
	(controls->release)[8] = (t_kfuncs) { k_trscamrz, K_S };
	(controls->release)[9] = (t_kfuncs) { k_chmode, K_P };
	(controls->release)[10] = (t_kfuncs) { NULL, 0 };
}
*/

void	set_controls(t_controls *controls)
{
	set_kfuncs(controls);
	controls->mode = 0;
}
