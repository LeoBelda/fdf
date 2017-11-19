/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sclmat4new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:58:32 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 20:03:42 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	sclmat4new(double x, double y, double z)
{
	t_mat4	sclmat;

	sclmat.x = vec4new(x, 0.0, 0.0, 0.0);
	sclmat.y = vec4new(0.0, y, 0.0, 0.0);
	sclmat.z = vec4new(0.0, 0.0, z, 0.0);
	sclmat.w = vec4new(0.0, 0.0, 0.0, 1.0);
	return (sclmat);
}
