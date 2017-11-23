/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 21:29:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	get_view_mat(t_cam *cam, t_modmat camst)
{
	t_mat4	view_mat;
	t_vec4	x_vec;
	t_vec4	y_vec;
	t_vec4	z_vec;

	z_vec = norm_vec4(
			vec4new(cam->target.x - cam->eye.x, cam->target.y - cam->eye.y,
					cam->target.z - cam->eye.z, 1.0));
	x_vec = cross_product(norm_vec4(cam->up), z_vec);
	y_vec = cross_product(z_vec, x_vec);
	/*
	print_vec4(x_vec);
	ft_putendl("");
	print_vec4(y_vec);
	ft_putendl("");
	print_vec4(z_vec);
	ft_putendl("");
	sleep(1);
	*/
	view_mat =	mat4xmat4(rotymat4new(deg_rad(camst.ry)),
				mat4xmat4(rotxmat4new(deg_rad(camst.rx)),
				mat4xmat4(rotzmat4new(deg_rad(camst.rz)),
			mat4new(vec4new(x_vec.x, y_vec.x, z_vec.x, 0.0),
						vec4new(x_vec.y, y_vec.y, z_vec.y, 0.0),
						vec4new(x_vec.z, y_vec.z, z_vec.z, 0.0),
						vec4new(-(cam->eye.x), -(cam->eye.y), -(cam->eye.z), 1.0)))));
return (view_mat);
}

static t_mat4	get_model_mat(t_modmat initst)
{
	return (
			mat4xmat4(trsmat4new(initst.tx, initst.ty, initst.tz),
			mat4xmat4(rotzmat4new(deg_rad(initst.rz)),
			mat4xmat4(rotymat4new(deg_rad(initst.ry)),
			mat4xmat4(rotxmat4new(deg_rad(initst.rx)),
			sclmat4new(initst.s, initst.s, initst.s)
			)))));
}

static t_mat4	get_eye_mat(t_modmat camst)
{
	return (
			trsmat4new(camst.tx, camst.ty, camst.tz)
			);
}

static t_mat4	get_target_mat(t_modmat camst)
{
	return (
			mat4xmat4(trsmat4new(camst.tx, camst.ty, camst.tz),
			trsmat4new(0.0, 0.0, 50.0)
			));
}
/*
static t_mat4	get_up_mat(t_modmat camst)
{
	return (
			mat4xmat4(rotzmat4new(deg_rad(camst.rz)),
			mat4xmat4(rotymat4new(deg_rad(camst.ry)),
			rotxmat4new(deg_rad(camst.rx))
			)));
}
*/
void			set_matrices(t_matrices *matrices)
{
	matrices->cam->up = vec4new(0.0, 0.1, 0.0, 0.0);
	matrices->cam->eye = mat4xvec4(get_eye_mat(matrices->camst),
									vec4new(0.0, 0.0, 0.0, 1.0));
	matrices->cam->target = mat4xvec4(get_target_mat(matrices->camst),
									vec4new(0.0, 0.0, 0.0, 1.0));
	matrices->f_mat = mat4xmat4(matrices->pers_proj,
						mat4xmat4(get_model_mat(matrices->initst),
							get_view_mat(matrices->cam, matrices->camst)));
}
