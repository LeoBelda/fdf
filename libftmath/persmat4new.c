/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:59:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/30 20:47:41 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	persmat4new(double fovh, double fovl, double f, double n)
{
	t_mat4	pers;

	pers.x = vec4new(1.0 / (tan(deg_rad(fovh / 2.0))), 0.0, 0.0, 0.0);
	pers.y = vec4new(0.0, 1.0 / (tan(deg_rad(fovl / 2.0))), 0.0, 0.0);
	pers.z = vec4new(0.0, 0.0, -f / (f - n), -(f * n) / (f - n));
	pers.w = vec4new(0.0, 0.0, -1.0, 0.0);
	return (pers);
}
