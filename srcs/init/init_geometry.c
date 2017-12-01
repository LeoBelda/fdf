/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:31 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:13:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4			get_view_mat(t_vec4 eye, t_vec4 target, t_vec4 up)
{
	t_vec4	x_vec;
	t_vec4	y_vec;
	t_vec4	z_vec;

	z_vec = norm_vec4(
			vec4new(target.x - eye.x, target.y - eye.y,
					target.z - eye.z, 0.0));
	x_vec = cross_product(norm_vec4(up), z_vec);
	y_vec = cross_product(z_vec, x_vec);
	return (mat4new(vec4new(x_vec.x, y_vec.x, z_vec.x, 0.0),
					vec4new(x_vec.y, y_vec.y, z_vec.y, 0.0),
					vec4new(x_vec.z, y_vec.z, z_vec.z, 0.0),
					vec4new(-(eye.x),
							-(eye.y),
							-(eye.z), 1.0)));
}

static t_mat4	get_model_mat(t_modmat initst, t_map *map)
{
	return (mat4xmat4(trsmat4new(initst.tx, initst.ty, initst.tz),
			mat4xmat4(trsmat4new(
						map->mid_mod.x, map->mid_mod.y, map->mid_mod.z),
			mat4xmat4(rotymat4new(initst.ry),
			mat4xmat4(rotxmat4new(initst.rx),
			mat4xmat4(rotzmat4new(initst.rz),
			mat4xmat4(trsmat4new(
						-map->mid_mod.x, -map->mid_mod.y, -map->mid_mod.z),
					sclmat4new(initst.s, initst.s, initst.s))))))));
}

static void		load_view_presets(t_matrices *matrices, t_map *map)
{
	matrices->views->stock_size = 1;
	matrices->views->switching = 0;
	if (!(matrices->views->stock = ft_memalloc(sizeof(t_mat4set) *
										matrices->views->stock_size)))
		error_exit("");
	matrices->eye_pos = mat4xvec4(
			trsmat4new(0.0, -(map->max_z + map->min_z / 1.5), 0.0),
			map->mid_mod);
	(matrices->views->stock[0]) = get_view_mat(matrices->eye_pos,
		mat4xvec4(trsmat4new(0.0, 0.0, 50.0), matrices->eye_pos),
		vec4new(0.0, 1.0, 0.0, 0.0));
}

static void		load_proj_presets(t_mat4set *projs)
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

void			init_geometry(t_matrices *matrices, t_map *map)
{
	if (!(matrices->views = ft_memalloc(sizeof(t_mat4set))))
		error_exit("");
	if (!(matrices->projs = ft_memalloc(sizeof(t_mat4set))))
		error_exit("");
	matrices->initst.rx = 90.0;
	matrices->initst.ry = 0.0;
	matrices->initst.rz = 0.0;
	matrices->initst.tx = 0.0;
	matrices->initst.ty = 0.0;
	matrices->initst.tz = 0.0;
	matrices->initst.s = 1.0;
	ft_bzero(&(matrices->movement), sizeof(t_modmat));
	matrices->movement.s = 1.0;
	matrices->model_mat = get_model_mat(matrices->initst, map);
	load_view_presets(matrices, map);
	matrices->views->active = matrices->views->stock[0];
	matrices->views->target = matrices->views->stock[0];
	matrices->views->from = matrices->views->stock[0];
	load_proj_presets(matrices->projs);
	matrices->projs->active = matrices->projs->stock[0];
	matrices->projs->target = matrices->projs->stock[0];
	matrices->projs->from = matrices->projs->stock[0];
	matrices->projmode = P_DEFAULT;
}
