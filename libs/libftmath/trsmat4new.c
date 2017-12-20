/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsmat4new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:13:51 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 17:18:46 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	trsmat4new(double x, double y, double z)
{
	t_mat4	trsmat;

	trsmat.x = vec4new(1.0, 0.0, 0.0, 0.0);
	trsmat.y = vec4new(0.0, 1.0, 0.0, 0.0);
	trsmat.z = vec4new(0.0, 0.0, 1.0, 0.0);
	trsmat.w = vec4new(x, y, z, 1.0);
	return (trsmat);
}
