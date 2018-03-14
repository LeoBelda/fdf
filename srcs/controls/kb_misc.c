/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:36:00 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/14 14:06:46 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_map *map)
{
	free(map->vertices);
	free(map->mod_vertices);
	free(map->target_vtx_y);
	free(map->world_coords_glb);
	free(map->world_vtx);
	free(map->m_world_vtx);
	free(map->distancesxy);
	free(map->distancesxz);
	free(map->proj);
	free(map->draw);
	free(map->clip);
	free(map->starfuncs);
}

static void	free_all_the_stuff(t_env *e)
{
	free_map(e->map);
}

void		k_exit(t_env *e, int flag)
{
	if (flag == 0)
		return ;
	if (mlx_destroy_image(e->mlx, e->img->img) == -1)
		error_exit("Failed to destroy image");
	free_all_the_stuff(e);
	exit(0);
}
