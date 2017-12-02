/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_audio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:10:56 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/02 22:18:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_audio(float *spectrum, t_map *map)
{
	size_t	i;

	(void)spectrum;
	i = 0;
	while (i < map->nb_vtx)
	{
		map->mod_vertices[i].z = map->vertices[i].z * spectrum[0];
		map->mod_vertices[i].y = map->vertices[i].y;
		map->mod_vertices[i].x = map->vertices[i].x;
		map->mod_vertices[i].w = map->vertices[i].w;
		i++;
	}
}
