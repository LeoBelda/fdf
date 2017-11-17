/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:28 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/17 20:09:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec4	define_eye(void)
{
	t_vec4	eye;

	eye.x = 90.0;
	eye.y = 50.0;
	eye.z = 50.0;
	eye.w = 0.0;
	return (eye);
}

static t_vec4	define_target(void)
{
	t_vec4	target;

	target.x = 90.0;
	target.y = 50.0;
	target.z = 0.0;
	target.w = 0.0;
	return (target);
}

static t_vec4	define_up(void)
{
	t_vec4	up;

	up.x = 0.0;
	up.y = 1.0;
	up.z = 0.0;
	up.w = 0.0;
	return (up);
}

void	position_camera(t_cam **cam)
{
	if (!(*cam = ft_memalloc(sizeof(t_cam))))
		error_exit("");
	(*cam)->eye = define_eye();
	(*cam)->target = define_target();
	(*cam)->up = define_up();
}
