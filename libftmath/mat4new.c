/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:43:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 14:00:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	mat4new(t_vec4 x, t_vec4 y, t_vec4 z, t_vec4 w)
{
	t_mat4	mat;

	mat.x.x = x.x;
	mat.x.y = y.x;
	mat.x.z = z.x;
	mat.x.w = w.x;
	mat.y.x = x.y;
	mat.y.y = y.y;
	mat.y.z = z.y;
	mat.y.w = w.y;
	mat.z.x = x.z;
	mat.z.y = y.z;
	mat.z.z = z.z;
	mat.z.w = w.z;
	mat.w.x = w.x;
	mat.w.y = w.x;
	mat.w.z = w.x;
	mat.w.w = w.x;
	return (mat);
}
