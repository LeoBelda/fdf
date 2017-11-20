/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 15:18:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	calculate_view_mat(t_cam *cam)
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

void	position_camera(t_cam **cam)
{
	if (!(*cam = ft_memalloc(sizeof(t_cam))))
		error_exit("");
	(*cam)->eye = vec4new(130.0, 50.0, 50.0, 0.0);
	(*cam)->target = vec4new(90.0, 50.0, 0.0, 0.0);
	(*cam)->up = vec4new(-0.5, 1.0, 0.0, 0.0);
}
