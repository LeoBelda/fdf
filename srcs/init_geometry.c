/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:31 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 13:00:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	get_view_mat(t_cam *cam)
{
	t_vec4	x_vec;
	t_vec4	y_vec;
	t_vec4	z_vec;

	z_vec = norm_vec4(
			vec4new(cam->target.x - cam->eye.x, cam->target.y - cam->eye.y,
					cam->target.z - cam->eye.z, 0.0));
	x_vec = cross_product(norm_vec4(cam->up), z_vec);
	y_vec = cross_product(z_vec, x_vec);
	return (mat4new(vec4new(x_vec.x, y_vec.x, z_vec.x, 0.0),
		  			  vec4new(x_vec.y, y_vec.y, z_vec.y, 0.0),
					  vec4new(x_vec.z, y_vec.z, z_vec.z, 0.0),
					  vec4new(-(vec4xvec4(x_vec, cam->eye)),
						  	  -(vec4xvec4(y_vec, cam->eye)),
							  -(vec4xvec4(z_vec, cam->eye)), 1.0)));
}

static t_mat4	get_model_mat(t_modmat initst)
{
	return (mat4xmat4(trsmat4new(initst.tx, initst.ty, initst.tz),
			mat4xmat4(rotymat4new(initst.ry),
			mat4xmat4(rotxmat4new(initst.rx),
			mat4xmat4(rotzmat4new(initst.rz),
					  sclmat4new(initst.s, initst.s, initst.s))))));
}

void	init_geometry(t_matrices *matrices)
{
	matrices->initst.rx = 33.0;
	matrices->initst.ry = 0.0;
	matrices->initst.rz = 0.0;
	matrices->initst.tx = -400.0;
	matrices->initst.ty = -300.0;
	matrices->initst.tz = 0.0;
	matrices->initst.s = 1.0;
	ft_bzero(&(matrices->movement), sizeof(t_modmat));
	matrices->movement.s = 1.0;
	matrices->cam->eye = vec4new(0.0, 0.0, 450.0, 1.0);
	matrices->cam->target = vec4new(0.0, 0.0, 500.0, 1.0);
	matrices->cam->up = vec4new(0.0, 1.0, 0.0, 0.0);
	matrices->ortho_mat = orthomat4new(frustrumnew(1000.0, 562.5, 2000.0, -2000.0));
	matrices->pers_mat = persmat4new(90.0, 50.625, 1000.0, 1.0);
	matrices->view_mat = get_view_mat(matrices->cam);
	matrices->model_mat = get_model_mat(matrices->initst);
}