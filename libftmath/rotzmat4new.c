/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotzmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:32:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/25 23:19:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotzmat4new(double z)
{
	t_mat4	rotmat;
	double	rad;

	rad = deg_rad(z);

	rotmat.x = vec4new(cos(rad), sin(rad), 0.0, 0.0);
	rotmat.y = vec4new(-sin(rad), cos(rad), 0.0, 0.0);
	rotmat.z = vec4new(0.0, 0.0, 1.0, 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
