/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:05:16 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 19:27:51 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dst_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->dstfuncs[i].dstmode != DST_LAST)
	{
		if (map->dstmode == map->dstfuncs[i].dstmode)
		{
			map->dstfuncs[i].f(map);
			break ;
		}
		i++;
	}
}
