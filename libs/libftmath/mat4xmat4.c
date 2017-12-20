/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4xmat4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:03:47 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 20:33:44 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	mat4xmat4(t_mat4 a, t_mat4 b)
{
	t_mat4	mat;

	mat.x = mat4xvec4(a, b.x);
	mat.y = mat4xvec4(a, b.y);
	mat.z = mat4xvec4(a, b.z);
	mat.w = mat4xvec4(a, b.w);
	return (mat);
}
