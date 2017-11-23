/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:59:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 01:58:42 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	persmat4new(t_frustrum fr)
{
	t_mat4	pers;

	pers.x = vec4new((2.0 * fr.n) / (fr.r - fr.l), 0.0, 0.0, 0.0);
	pers.y = vec4new(0.0, (2.0 * fr.n) / (fr.t - fr.b), 0.0, 0.0);
	pers.z = vec4new((fr.r + fr.l) / (fr.r - fr.l),
					 (fr.t + fr.b) / (fr.t - fr.b),
					-(fr.f + fr.n) / (fr.f - fr.n), -1.0);
	pers.w = vec4new(0.0, 0.0, -(2 * fr.f * fr.n) / (fr.f - fr.n), 0.0);
	return (pers);
}
