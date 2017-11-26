/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 15:17:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	refresh_view_mat(t_mat4 view_mat, t_modmat movement)
{
	return (mat4xmat4(trsmat4new(movement.tx, movement.ty, movement.tz),
			mat4xmat4(rotymat4new(movement.ry),
			mat4xmat4(rotxmat4new(movement.rx),
			mat4xmat4(rotzmat4new(movement.rz),
			mat4xmat4(sclmat4new(movement.s, movement.s, movement.s),
				view_mat))))));
}

void			set_matrices(t_matrices *matrices)
{
	matrices->view_mat = refresh_view_mat(matrices->view_mat,
											matrices->movement);
	matrices->f_mat = mat4xmat4(matrices->pers_mat,
					  mat4xmat4(matrices->view_mat,
					 		    matrices->model_mat));
}
