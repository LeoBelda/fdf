/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthomat4new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:15:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 22:56:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	orthomat4new(t_frustrum fr)
{
	t_mat4	ortho;

	ortho.x = vec4new(1.0 / fr.r, 0.0, 0.0, 0.0);
	ortho.y = vec4new(0.0, 1.0 / fr.t, 0.0, 0.0);
	ortho.z = vec4new(0.0, 0.0, -2.0 / (fr.f - fr.n), 0.0);
	ortho.w = vec4new(0.0, 0.0, -(fr.f + fr.n) / (fr.f - fr.n), 1.0);
	return (ortho);
}
