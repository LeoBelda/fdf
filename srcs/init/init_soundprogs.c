/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_soundprogs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:14:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/08 16:49:37 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_sr_funcs(t_sound *sound)
{
	if (!(sound->srfuncs = ft_memalloc(sizeof(t_srfuncs) * 4)))
		error_exit("");
	(sound->srfuncs)[0] = (t_srfuncs) { sr_default, SR_DEFAULT };
	(sound->srfuncs)[1] = (t_srfuncs) { sr_bass_alti, SR_BASS_ALTI };
	(sound->srfuncs)[2] = (t_srfuncs) { sr_total_alti, SR_TOTAL_ALTI };
	(sound->srfuncs)[3] = (t_srfuncs) { NULL, 0 };
}

void	set_sc_funcs(t_sound *sound)
{
	if (!(sound->scfuncs = ft_memalloc(sizeof(t_scfuncs) * 4)))
		error_exit("");
	(sound->scfuncs)[0] = (t_scfuncs) { sc_default, SC_DEFAULT };
	(sound->scfuncs)[1] = (t_scfuncs) { sc_total_vision, SC_TOTAL_VISION };
	(sound->scfuncs)[2] = (t_scfuncs) { sc_total_unvision, SC_TOTAL_UNVISION };
	(sound->scfuncs)[3] = (t_scfuncs) { NULL, 0 };
}
