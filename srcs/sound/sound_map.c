/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_audio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:10:56 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 16:01:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_sound_map(t_sound *sound, t_map *map)
{
	size_t	i;

	i = 0;
	if (sound->mode == S_ON)
		while (sound->srfuncs[i].srmode)
		{
			if (sound->srmode == sound->srfuncs[i].srmode)
			{
				sound->srfuncs[i].f(sound->data->p_spec, map);
				break ;
			}
			i++;
		}
}
