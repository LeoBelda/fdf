/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:52:15 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/17 16:12:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_parsed_map(t_map *map)
{
	while (map->vertices)
	{
		printf("x: %f  y: %f  z: %f  w: %f\n",
				((t_vec3d*)(map->vertices->content))->x,
				((t_vec3d*)(map->vertices->content))->y,
				((t_vec3d*)(map->vertices->content))->z,
				((t_vec3d*)(map->vertices->content))->w);
		map->vertices = map->vertices->next;
	}
}
