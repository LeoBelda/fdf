/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotxmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:24:05 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/25 23:18:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotxmat4new(double x)
{
	t_mat4	rotmat;
	double	rad;

	rad = deg_rad(x);
	rotmat.x = vec4new(1.0, 0.0, 0.0, 0.0);
	rotmat.y = vec4new(0.0, cos(rad), sin(rad), 0.0);
	rotmat.z = vec4new(0.0, -sin(rad), cos(rad), 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
