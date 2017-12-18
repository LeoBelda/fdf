/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 10:24:37 by lbelda           ###   ########.fr       */
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

void			get_eye_pos(t_matrices *matrices)
{
	matrices->eye_pos = vec4xmat4(vec4neg(matrices->views->active.w),
					mat4new(matrices->views->active.x,
						matrices->views->active.y,
					matrices->views->active.z, vec4new(0.0, 0.0, 0.0, 1.0)));
	matrices->diff_eye_pos = vec4new(
			matrices->eye_pos.x - matrices->prev_eye_pos.x,
			matrices->eye_pos.y - matrices->prev_eye_pos.y,
			matrices->eye_pos.z - matrices->prev_eye_pos.z, 0.0);
	matrices->prev_eye_pos = matrices->eye_pos;
}

static void		switch_mat4(t_env *e, t_mat4set *set)
{
	if (set->progress == 100)
	{
		set->active = set->target;
		set->from = set->target;
		set->progress = 0;
		set->switching = 0;
		if (e)
			e->controls->active = e->controls->target;
		return ;
	}
	set->active = mat4_interi(set->from, set->target, 100, set->progress);
	set->progress++;
}

static void		check_mode(t_mat4set *set)
{
	size_t	i;

	i = 0;
	while (!ft_ismemzero(&(set->stock[i].gmode), sizeof(t_gmodes)))
	{
		if (!ft_memcmp(&(set->gmode), &(set->stock[i].gmode), sizeof(t_gmodes)))
		{
			if (ft_memcmp(&set->target, &set->stock[i].mat, sizeof(t_mat4)))
			{
				set->target = set->stock[i].mat;
				set->from = set->active;
				set->switching = 1;
				set->progress = 0;
				break ;
			}
			else
				break ;
		}
		i++;
	}
}

void			set_matrices(t_env *e, t_matrices *matrices)
{
	check_mode(matrices->views);
	check_mode(matrices->projs);
	if (matrices->views->switching == 1)
		switch_mat4(e, matrices->views);
	if (matrices->projs->switching == 1)
		switch_mat4(NULL, matrices->projs);
	matrices->views->active = refresh_view_mat(matrices->views->active,
									matrices->movement);
	matrices->f_mat = mat4xmat4(matrices->projs->active,
						matrices->views->active);
}
