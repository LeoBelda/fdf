/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 20:16:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	get_view_mat(t_cam *cam)
{
	t_mat4	view_mat;
	t_vec4	x_vec;
	t_vec4	y_vec;
	t_vec4	z_vec;

	z_vec = norm_vec4(
			vec4new(cam->eye.x - cam->target.x, cam->eye.y - cam->target.y,
					cam->eye.z - cam->target.z, cam->eye.w - cam->target.w));
	x_vec = cross_product(norm_vec4(cam->up), z_vec);
	y_vec = cross_product(z_vec, x_vec);
	view_mat = mat4new(x_vec, y_vec, z_vec, 
						vec4new(cam->eye.x, cam->eye.y, cam->eye.z, 1.0));
	return (view_mat);
}

static t_mat4	get_model_mat(t_modmat *initst)
{
	return (
			mat4xmat4(trsmat4new(initst->tx, initst->ty, initst->tz),
			mat4xmat4(rotzmat4new(deg_rad(initst->rz)),
			mat4xmat4(rotymat4new(deg_rad(initst->ry)),
			mat4xmat4(rotxmat4new(deg_rad(initst->rx)),
			sclmat4new(initst->s, initst->s, initst->s)
			)))));
}

void			set_matrices(t_matrices *matrices)
{
	matrices->f_mat = mat4xmat4(get_view_mat(matrices->cam),
						get_model_mat(matrices->initst));
}
