/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:15:02 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 21:11:17 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_kfuncs	*kfuncs_grd(void)
{
	t_kfuncs	*config;

	if (!(config = ft_memalloc(sizeof(t_kfuncs) * 15)))
		error_exit("");
	config[0] = (t_kfuncs) { k_rotcamz, K_LEFT };
	config[1] = (t_kfuncs) { k_rotcamrz, K_RIGHT };
	config[2] = (t_kfuncs) { k_rotcamrx, K_UP };
	config[3] = (t_kfuncs) { k_rotcamx, K_DOWN };
	config[4] = (t_kfuncs) { k_trscamz, K_W };
	config[5] = (t_kfuncs) { k_trscamrz, K_S };
	config[6] = (t_kfuncs) { k_rotcamry, K_A };
	config[7] = (t_kfuncs) { k_rotcamy, K_D };
	config[8] = (t_kfuncs) { k_chpov, K_P };
	config[9] = (t_kfuncs) { k_chspace, K_H };
	config[10] = (t_kfuncs) { k_chcolor_stock, K_C };
	config[11] = (t_kfuncs) { k_chcolor_program, K_F };
	config[12] = (t_kfuncs) { k_chbuff_mode, K_B };
	config[13] = (t_kfuncs) { k_exit, K_ESC };
	config[14] = (t_kfuncs) { NULL, 0 };
	return (config);
}

static t_kfuncs	*kfuncs_sky(void)
{
	t_kfuncs	*config;

	if (!(config = ft_memalloc(sizeof(t_kfuncs) * 10)))
		error_exit("");
	config[0] = (t_kfuncs) { k_trscamx, K_A };
	config[1] = (t_kfuncs) { k_trscamrx, K_D };
	config[2] = (t_kfuncs) { k_trscamy, K_W };
	config[3] = (t_kfuncs) { k_trscamry, K_S };
	config[4] = (t_kfuncs) { k_chpov, K_P };
	config[5] = (t_kfuncs) { k_chcolor_stock, K_C };
	config[6] = (t_kfuncs) { k_chcolor_program, K_F };
	config[7] = (t_kfuncs) { k_chbuff_mode, K_B };
	config[8] = (t_kfuncs) { k_exit, K_ESC };
	config[9] = (t_kfuncs) { NULL, 0 };
	return (config);
}

static t_kfuncs	*kfuncs_swi(void)
{
	t_kfuncs	*config;

	if (!(config = ft_memalloc(sizeof(t_kfuncs) * 6)))
		error_exit("");
	config[0] = (t_kfuncs) { k_chpov, K_P };
	config[1] = (t_kfuncs) { k_chcolor_stock, K_C };
	config[2] = (t_kfuncs) { k_chcolor_program, K_F };
	config[3] = (t_kfuncs) { k_chbuff_mode, K_B };
	config[4] = (t_kfuncs) { k_exit, K_ESC };
	config[5] = (t_kfuncs) { NULL, 0 };
	return (config);
}

static void		set_kbsync(t_controls *controls)
{
	if (!(controls->kbsync = ft_memalloc(sizeof(t_kbsync) * 3)))
		error_exit("");
	(controls->kbsync)[0] = (t_kbsync) { M_GRD, KB_GRD };
	(controls->kbsync)[1] = (t_kbsync) { M_SKY, KB_SKY };
	(controls->kbsync)[2] = (t_kbsync) { 0, 0 };
}

void			init_controls(t_env *e)
{
	if (!(e->controls->presets = ft_memalloc(sizeof(t_kbpreset) * 4)))
		error_exit("");
	(e->controls->presets)[0] = (t_kbpreset) { kfuncs_grd(), KB_GRD };
	(e->controls->presets)[1] = (t_kbpreset) { kfuncs_swi(), KB_SWI };
	(e->controls->presets)[2] = (t_kbpreset) { kfuncs_sky(), KB_SKY };
	(e->controls->presets)[3] = (t_kbpreset) { NULL, 0 };
	set_kbsync(e->controls);
}
