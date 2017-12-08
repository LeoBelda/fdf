/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:06:36 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/08 16:48:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_state_eno(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_STOCK;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_DEFAULT;
	e->matrices->views->gmode.vmode = V_GRD;
	if (e->sound->smode == S_ON)
	{
		e->map->dstmode = DST_AROUND_FLAT;
		e->sound->srmode = SR_TOTAL_ALTI;
		e->sound->scmode = SC_TOTAL_VISION;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->map->dstmode = DST_DEFAULT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
}

void	set_state_satin(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_HYPER;
	e->colors->bmode = B_TRIPPY;
	e->matrices->projs->gmode.pmode = P_WIDE;
	e->matrices->views->gmode.vmode = V_GRD;
	if (e->sound->smode == S_ON)
	{
		e->map->dstmode = DST_AROUND_FLAT;
		e->sound->srmode = SR_TOTAL_ALTI;
		e->sound->scmode = SC_TOTAL_UNVISION;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->map->dstmode = DST_DEFAULT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
}


void	set_state_psych(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_DISCO;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_SPACE;
	e->matrices->views->gmode.vmode = V_GRD;
	if (e->sound->smode == S_ON)
	{
		e->map->dstmode = DST_DEFAULT;
		e->sound->srmode = SR_BASS_ALTI;
		e->sound->scmode = SC_TOTAL_VISION;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->map->dstmode = DST_DEFAULT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
}

void	set_state_test(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_STOCK;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_DEFAULT;
	e->matrices->views->gmode.vmode = V_GRD;
	if (e->sound->smode == S_ON)
	{
		e->map->dstmode = DST_DEFAULT;
		e->sound->srmode = SR_BASS_ALTI;
		e->sound->scmode = SC_TOTAL_VISION;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->map->dstmode = DST_DEFAULT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
}
