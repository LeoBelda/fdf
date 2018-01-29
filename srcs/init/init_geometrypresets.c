/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometrypresets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:56:40 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 12:29:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_view_presets(t_matrices *matrices, t_map *map)
{
	if (!(matrices->views->stock = ft_memalloc(sizeof(t_matstock) * 3)))
		error_exit("");
	matrices->eye_pos = (t_vec4){0.0, map->min_y - map->max_y, 0.0, 1.0};
	matrices->prev_eye_pos = matrices->eye_pos;
	(matrices->views->stock[0]) = (t_matstock)
		{ get_view_mat(matrices->eye_pos,
		mat4xvec4(trsmat4new(0.0, 0.0, 50.0), matrices->eye_pos),
		vec4new(0.0, 1.0, 0.0, 0.0)), .gmode.vmode = V_GRD };
	(matrices->views->stock[1]) = (t_matstock)
		{ trsmat4new(0.0, 0.0, 0.0), .gmode.vmode = V_SKY };
	(matrices->views->stock[2]) = (t_matstock)
		{ trsmat4new(0.0, 0.0, 0.0), .gmode.vmode = 0 };
	matrices->views->active = matrices->views->stock[0].mat;
	matrices->views->target = matrices->views->stock[0].mat;
	matrices->views->from = matrices->views->stock[0].mat;
	matrices->views->stock_size = 3;
	matrices->views->switching = 0;
}

void	load_proj_presets(t_mat4set *projs)
{
	if (!(projs->stock = ft_memalloc(sizeof(t_matstock) * 6)))
		error_exit("");
	(projs->stock[0]) = (t_matstock)
			{ persmat4new(110.0, 78.0, 1000.0, 1.0), .gmode.pmode = P_DEFAULT };
	(projs->stock[1]) = (t_matstock)
			{ persmat4new(150.0, 90.0, 1000.0, 1.0), .gmode.pmode = P_WIDE };
	(projs->stock[2]) = (t_matstock)
			{ persmat4new(130.0, 85.0, 1000.0, 3.0), .gmode.pmode = P_SPACE };
	(projs->stock[3]) = (t_matstock)
			{ persmat4new(45.0, 22.0, 1000.0, 1.0), .gmode.pmode = P_SKY };
	(projs->stock[4]) = (t_matstock)
			{ orthomat4new(frustrumnew(1000.0, 562.5, 5000.0, -5000.0)),
													.gmode.pmode = P_ORTHO };
	(projs->stock[5]) = (t_matstock) { trsmat4new(0.0, 0.0, 0.0),
													.gmode.pmode = 0 };
	projs->active = projs->stock[0].mat;
	projs->target = projs->stock[0].mat;
	projs->from = projs->stock[0].mat;
	projs->stock_size = 5;
	projs->switching = 0;
}
