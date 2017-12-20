/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4xvec4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:46:25 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 19:21:01 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec4	mat4xvec4(t_mat4 mat, t_vec4 vec)
{
	t_vec4	ret;

	ret.x = vec4xvec4(vec4new(mat.x.x, mat.y.x, mat.z.x, mat.w.x), vec);
	ret.y = vec4xvec4(vec4new(mat.x.y, mat.y.y, mat.z.y, mat.w.y), vec);
	ret.z = vec4xvec4(vec4new(mat.x.z, mat.y.z, mat.z.z, mat.w.z), vec);
	ret.w = vec4xvec4(vec4new(mat.x.w, mat.y.w, mat.z.w, mat.w.w), vec);
	return (ret);
}
