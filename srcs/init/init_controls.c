/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:15:02 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/20 01:50:13 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (!(e->controls->presets = ft_memalloc(sizeof(t_kbpreset) * 5)))
		error_exit("");
	(e->controls->presets)[0] = (t_kbpreset) { kfuncs_grd(), KB_GRD };
	(e->controls->presets)[1] = (t_kbpreset) { kfuncs_swi(), KB_SWI };
	(e->controls->presets)[2] = (t_kbpreset) { kfuncs_sky(), KB_SKY };
	(e->controls->presets)[3] = (t_kbpreset) { kfuncs_rt(), KB_RT };
	(e->controls->presets)[4] = (t_kbpreset) { NULL, 0 };
	set_kbsync(e->controls);
	SDL_GameControllerEventState(SDL_ENABLE);
	e->controls->ps3 = SDL_GameControllerOpen(0);
}
