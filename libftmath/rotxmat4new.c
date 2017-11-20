/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotxmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:24:05 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 17:34:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotxmat4new(double x)
{
	t_mat4	rotmat;

	rotmat.x = vec4new(1.0, 0.0, 0.0, 0.0);
	rotmat.y = vec4new(0.0, cos(x), sin(x), 0.0);
	rotmat.z = vec4new(0.0, -sin(x), cos(x), 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
