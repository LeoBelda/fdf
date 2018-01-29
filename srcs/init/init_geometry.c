/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:31 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 12:22:06 by lbelda           ###   ########.fr       */
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
						map->mid_mod.x, 0., 0.),
			mat4xmat4(rotymat4new(initst.ry),
			mat4xmat4(rotxmat4new(initst.rx),
			mat4xmat4(rotzmat4new(initst.rz),
			mat4xmat4(trsmat4new(
						-map->mid_mod.x, 0., 0.),
					sclmat4new(initst.s, initst.s, initst.s))))))));
}

static void		get_world_coords(t_mat4 modelmat, t_map *map)
{
	size_t	i;

	i = 0;
	map->min_y = MAX_INT;
	map->max_y = MIN_INT;
	while (i < map->nb_vtx_glb)
	{
		map->world_coords_glb[i] = mat4xvec4(modelmat, map->vertices_glb[i]);
		if ((int)(map->world_coords_glb)[i].y > map->max_y)
			map->max_y = (int)(map->world_coords_glb)[i].y;
		if ((int)(map->world_coords_glb)[i].y < map->min_y)
			map->min_y = (int)(map->world_coords_glb)[i].y;
		i++;
	}
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
	get_world_coords(matrices->model_mat, map);
	load_view_presets(matrices, map);
	load_proj_presets(matrices->projs);
	set_dstfuncs(map);
	set_vdstfuncs(map);
}
