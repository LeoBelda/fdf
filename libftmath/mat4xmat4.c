/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4xmat4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:03:47 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 14:21:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	mat4xmat4(t_mat4 a, t_mat4 b)
{
	t_mat4	mat;

	mat.x = mat4xvec4(a, vec4new(b.x.x, b.y.x, b.z.x, b.w.x));
	mat.y = mat4xvec4(a, vec4new(b.x.y, b.y.y, b.z.y, b.w.y));
	mat.z = mat4xvec4(a, vec4new(b.x.z, b.y.z, b.z.z, b.w.z));
	mat.w = mat4xvec4(a, vec4new(b.x.w, b.y.w, b.z.w, b.w.w));

	return (mat);
}
