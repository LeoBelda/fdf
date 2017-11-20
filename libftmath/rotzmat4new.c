/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotzmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:32:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 17:34:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotzmat4new(double z)
{
	t_mat4	rotmat;

	rotmat.x = vec4new(cos(z), sin(z), 0.0, 0.0);
	rotmat.y = vec4new(-sin(z), cos(z), 0.0, 0.0);
	rotmat.z = vec4new(0.0, 0.0, 1.0, 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
