/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:06:36 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/17 14:34:40 by lbelda           ###   ########.fr       */
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
	e->controls->target = NULL;
}

void	set_state_quiet(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_HYPER;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_SPACE;
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
	e->controls->target = NULL;
}

void	set_state_loud(t_env *e)
{
	e->mode = M_GRD;
	e->colors->cmode = C_DISCO;
	e->colors->bmode = B_DEFAULT;
	e->matrices->projs->gmode.pmode = P_WIDE;
	e->matrices->views->gmode.vmode = V_GRD;
	if (e->sound->smode == S_ON)
	{
		e->map->dstmode = DST_AROUND_FLAT;
		e->sound->srmode = SR_BASS_ALTI;
		e->sound->scmode = SC_TOTAL_UNVISION;
		e->map->vdstmode = VDST_SOUND_TOTAL;
	}
	else
	{
		e->map->dstmode = DST_AROUND_FLAT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_DEFAULT;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
	e->controls->target = NULL;
}

void	set_state_default(t_env *e)
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
		e->map->vdstmode = VDST_DEFAULT;
	}
	else
	{
		e->map->dstmode = DST_DEFAULT_NS;
		e->sound->srmode = SR_DEFAULT;
		e->sound->scmode = SC_TOTAL_VISION;
		e->map->vdstmode = VDST_DEFAULT;
	}
	switch_kbmode(e, &e->controls->active, KB_GRD);
	e->controls->target = NULL;
}

void	set_state_rt(t_env *e)
{
	switch_kbmode(e, &e->controls->active, KB_RT);
	e->controls->target = NULL;
}
