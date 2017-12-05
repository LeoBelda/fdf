/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:55:01 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 00:00:26 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_sound_color(t_sound *sound, t_map *map, t_colorset active)
{
	size_t	i;

	i = 0;
	if (sound->mode == S_ON)
		while (sound->scfuncs[i].scmode)
		{
			if (sound->scmode == sound->scfuncs[i].scmode)
			{
				sound->scfuncs[i].f(map, active);
				break ;
			}
			i++;
		}
}
