/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:15:02 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:07:37 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_kfuncs_ground(t_controls *controls)
{
	if (!(controls->grd = ft_memalloc(sizeof(t_kfuncs) * 15)))
		error_exit("");
	(controls->grd)[0] = (t_kfuncs) { k_rotcamz, K_LEFT };
	(controls->grd)[1] = (t_kfuncs) { k_rotcamrz, K_RIGHT };
	(controls->grd)[2] = (t_kfuncs) { k_rotcamrx, K_UP };
	(controls->grd)[3] = (t_kfuncs) { k_rotcamx, K_DOWN };
	(controls->grd)[4] = (t_kfuncs) { k_trscamz, K_W };
	(controls->grd)[5] = (t_kfuncs) { k_trscamrz, K_S };
	(controls->grd)[6] = (t_kfuncs) { k_rotcamry, K_A };
	(controls->grd)[7] = (t_kfuncs) { k_rotcamy, K_D };
	(controls->grd)[8] = (t_kfuncs) { k_chpov, K_P };
	(controls->grd)[9] = (t_kfuncs) { k_chspace, K_H };
	(controls->grd)[10] = (t_kfuncs) { k_chcolor_stock, K_C };
	(controls->grd)[11] = (t_kfuncs) { k_chcolor_program, K_F };
	(controls->grd)[12] = (t_kfuncs) { k_chbuff_mode, K_B };
	(controls->grd)[13] = (t_kfuncs) { k_exit, K_ESC };
	(controls->grd)[14] = (t_kfuncs) { NULL, 0 };
}

static void	set_kfuncs_sky(t_controls *controls)
{
	if (!(controls->sky = ft_memalloc(sizeof(t_kfuncs) * 10)))
		error_exit("");
	(controls->sky)[0] = (t_kfuncs) { k_trscamx, K_A };
	(controls->sky)[1] = (t_kfuncs) { k_trscamrx, K_D };
	(controls->sky)[2] = (t_kfuncs) { k_trscamy, K_W };
	(controls->sky)[3] = (t_kfuncs) { k_trscamry, K_S };
	(controls->sky)[4] = (t_kfuncs) { k_chpov, K_P };
	(controls->sky)[5] = (t_kfuncs) { k_chcolor_stock, K_C };
	(controls->sky)[6] = (t_kfuncs) { k_chcolor_program, K_F };
	(controls->sky)[7] = (t_kfuncs) { k_chbuff_mode, K_B };
	(controls->sky)[8] = (t_kfuncs) { k_exit, K_ESC };
	(controls->sky)[9] = (t_kfuncs) { NULL, 0 };
}

void		init_controls(t_controls *controls)
{
	set_kfuncs_ground(controls);
	set_kfuncs_sky(controls);
}
