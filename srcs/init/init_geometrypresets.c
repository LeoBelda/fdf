/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometrypresets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:56:40 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 22:34:44 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_view_presets(t_matrices *matrices, t_map *map)
{
	matrices->views->stock_size = 1;
	matrices->views->switching = 0;
	if (!(matrices->views->stock = ft_memalloc(sizeof(t_mat4set) *
										matrices->views->stock_size)))
		error_exit("");
	matrices->eye_pos = mat4xvec4(
			trsmat4new(0.0, 0.0, 0.0),
			map->mid_mod);
	(matrices->views->stock[0]) = get_view_mat(matrices->eye_pos,
		mat4xvec4(trsmat4new(0.0, 0.0, 50.0), matrices->eye_pos),
		vec4new(0.0, 1.0, 0.0, 0.0));
}

void	load_proj_presets(t_mat4set *projs)
{
	projs->stock_size = 2;
	projs->switching = 0;
	if (!(projs->stock = ft_memalloc(sizeof(t_mat4set) *
										(projs->stock_size + 2))))
		error_exit("");
	(projs->stock[0]) = persmat4new(110.0, 78.0, 1000.0, 1.0);
	(projs->stock[1]) = persmat4new(45.0, 22.0, 1000.0, 1.0);
	(projs->stock[2]) = persmat4new(130.0, 85.0, 1000.0, 3.0);
	(projs->stock[3]) = orthomat4new(
					frustrumnew(1000.0, 562.5, 5000.0, -5000.0));
}
