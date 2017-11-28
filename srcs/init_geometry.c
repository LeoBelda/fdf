/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:31 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 01:58:14 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	get_view_mat(t_vec4 eye, t_vec4 target, t_vec4 up)
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
					  vec4new(-(vec4xvec4(x_vec, eye)),
						  	  -(vec4xvec4(y_vec, eye)),
							  -(vec4xvec4(z_vec, eye)), 1.0)));
}

static t_mat4	get_model_mat(t_modmat initst, t_map *map)
{
	return (mat4xmat4(trsmat4new(initst.tx, initst.ty, initst.tz),
			mat4xmat4(trsmat4new(map->mid_top.x, map->mid_top.y, 0.0),
			mat4xmat4(rotymat4new(initst.ry),
			mat4xmat4(rotxmat4new(initst.rx),
			mat4xmat4(rotzmat4new(initst.rz),
			mat4xmat4(trsmat4new(-map->mid_top.x, -map->mid_top.y, 0.0),
					  sclmat4new(initst.s, initst.s, initst.s))))))));
}

static void	load_view_presets(t_mat4set *views, t_map *map)
{
	views->stock_size = 2;
	views->switching = 0;
	if (!(views->stock = ft_memalloc(sizeof(t_mat4set) *
										views->stock_size)))
		error_exit("");
	(views->stock[0]) = get_view_mat(
		vec4new(map->mid_top.x, map->mid_top.y - 100, 0.0, 1.0),
		mat4xvec4(trsmat4new(0.0, 0.0, 50.0),
			vec4new(map->mid_top.x, map->mid_top.y - 100, 0.0, 1.0)),
		vec4new(0.0, 1.0, 0.0, 0.0));
	(views->stock[1]) = mat4xmat4(trsmat4new(0.0, 0.0, -4000.0),
						mat4xmat4(rotxmat4new(-90.0), views->stock[0]));

}

static void	load_proj_presets(t_mat4set *projs)
{
	projs->stock_size = 2;
	projs->switching = 0;
	if (!(projs->stock = ft_memalloc(sizeof(t_mat4set) *
										(projs->stock_size + 1))))
		error_exit("");
	(projs->stock[0]) = persmat4new(110.0, 78.0, 1000.0, 1.0);
	(projs->stock[1]) = persmat4new(40.0, 25.0, 1000.0, 1.0);
	(projs->stock[2]) = orthomat4new(frustrumnew(1000.0, 562.5, 5000.0, -5000.0));
}

void		init_geometry(t_matrices *matrices, t_map *map)
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
	load_view_presets(matrices->views, map);
	matrices->views->active = matrices->views->stock[0];
	matrices->views->target = matrices->views->stock[0];
	matrices->views->from = matrices->views->stock[0];
	load_proj_presets(matrices->projs);
	matrices->projs->active = matrices->projs->stock[0];
	matrices->projs->target = matrices->projs->stock[0];
	matrices->projs->from = matrices->projs->stock[0];
	matrices->model_mat = get_model_mat(matrices->initst, map);
}
