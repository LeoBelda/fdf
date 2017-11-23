/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthomat4new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:15:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 01:28:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	orthomat4new(t_frustrum fr)
{
	t_mat4	ortho;

	ortho.x = vec4new(2.0 / (fr.r - fr.l), 0.0, 0.0, 0.0);
	ortho.y = vec4new(0.0, 2.0 / (fr.t - fr.b), 0.0, 0.0);
	ortho.z = vec4new(0.0, 0.0, -2.0 / (fr.f - fr.n), 0.0);
	ortho.w = vec4new(-(fr.r + fr.l) / (fr.r - fr.l),
					-(fr.t + fr.b) / (fr.t - fr.b),
					-(fr.f + fr.n) / (fr.f - fr.n), 1.0);
	return (ortho);
}
