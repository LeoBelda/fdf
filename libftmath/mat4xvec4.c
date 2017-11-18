/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4xvec4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:46:25 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 14:02:22 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec4	mat4xvec4(t_mat4 mat, t_vec4 vec)
{
	t_vec4	ret;

	ret.x = vec4xvec4(mat.x, vec);
	ret.y = vec4xvec4(mat.y, vec);
	ret.z = vec4xvec4(mat.z, vec);
	ret.w = vec4xvec4(mat.w, vec);
	return (ret);
}
