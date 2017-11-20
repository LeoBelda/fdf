/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotymat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:28:49 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 17:34:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	rotymat4new(double y)
{
	t_mat4	rotmat;

	rotmat.x = vec4new(cos(y), 0.0, -sin(y), 0.0);
	rotmat.y = vec4new(0.0, 1.0, 0.0, 0.0);
	rotmat.z = vec4new(sin(y), 0.0, cos(y), 0.0);
	rotmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (rotmat);
}
