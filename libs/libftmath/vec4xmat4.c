/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4xmat4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:20:37 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 19:21:58 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec4	vec4xmat4(t_vec4 vec, t_mat4 mat)
{
	t_vec4	ret;

	ret.x = vec4xvec4(vec, mat.x);
	ret.y = vec4xvec4(vec, mat.y);
	ret.z = vec4xvec4(vec, mat.z);
	ret.w = vec4xvec4(vec, mat.w);
	return (ret);
}
