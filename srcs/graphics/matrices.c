/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 19:32:34 by lbelda           ###   ########.fr       */
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

t_vec4	get_eye_pos(t_mat4 active)
{
	return (vec4xmat4(vec4neg(active.w),
					mat4new(active.x, active.y,
					active.z, vec4new(0.0, 0.0, 0.0, 1.0))));
}

static void		switch_mat4(t_mat4set *set)
{
	if (set->progress == 100)
	{
		set->active = set->target;
		set->from = set->target;
		set->progress = 0;
		set->switching = 0;
		return ;
	}
	set->active = mat4_interi(set->from, set->target, 100, set->progress);
	set->progress++;
}

void			set_matrices(t_matrices *matrices)
{
	if (matrices->views->switching == 1 || matrices->projs->switching == 1)
	{
		switch_mat4(matrices->views);
		switch_mat4(matrices->projs);
	}
	else
	{
		matrices->views->active = refresh_view_mat(matrices->views->active,
									matrices->movement);

	}
	matrices->f_mat = mat4xmat4(matrices->projs->active,
					  mat4xmat4(matrices->views->active,
					 		    matrices->model_mat));
}
