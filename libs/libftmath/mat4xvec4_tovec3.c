/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4xvec4_tovec3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:29:29 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 10:38:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	mat4xvec4_tovec3(t_mat4 mat, t_vec4 vec)
{
	t_vec3	ret;

	mat.w.w = mat.x.w * vec.x + mat.y.w * vec.y
			+ mat.z.w * vec.z + mat.w.w * vec.w;
	ret.x = (mat.x.x * vec.x + mat.y.x * vec.y
			+ mat.z.x * vec.z + mat.w.x * vec.w) / mat.w.w;
	ret.y = (mat.x.y * vec.x + mat.y.y * vec.y
			+ mat.z.y * vec.z + mat.w.y * vec.w) / mat.w.w;
	ret.z = (mat.x.z * vec.x + mat.y.z * vec.y
			+ mat.z.z * vec.z + mat.w.z * vec.w) / mat.w.w;
	return (ret);
}
