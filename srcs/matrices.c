/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 21:35:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	get_view_mat4(t_cam *cam)
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

t_mat4	get_model_mat4(t_modmat *modmat)
{
	return (
			mat4xmat4(trsmat4new(modmat->tx, modmat->ty, modmat->tz),
			mat4xmat4(rotzmat4new(deg_rad(modmat->rx)),
			mat4xmat4(rotymat4new(deg_rad(modmat->ry)),
			mat4xmat4(rotxmat4new(deg_rad(modmat->rx)),
			sclmat4new(modmat->s, modmat->s, modmat->s)
			)))));
}
