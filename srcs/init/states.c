/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:06:36 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/07 00:00:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_state_basic(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_STOCK;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_DEFAULT;
	e->matrices->views->gmode.vmode = V_GRD;
	e->map->dstmode = DST_AROUND_FLAT;
	if (e->sound->smode == S_ON)
	{
		e->sound->srmode = SR_TOTAL_ALTI;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
}