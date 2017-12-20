/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotymat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:28:49 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/25 23:19:28 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotymat4new(double y)
{
	t_mat4	rotmat;
	double	rad;

	rad = deg_rad(y);
	rotmat.x = vec4new(cos(rad), 0.0, -sin(rad), 0.0);
	rotmat.y = vec4new(0.0, 1.0, 0.0, 0.0);
	rotmat.z = vec4new(sin(rad), 0.0, cos(rad), 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
