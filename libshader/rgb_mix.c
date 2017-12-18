/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_mix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 07:00:24 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/14 10:44:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshader.h"

t_rgb	rgb_mix(t_rgb c1, t_rgb c2, float ratio)
{
	return ((t_rgb) { .c= (t_srgb) {
			(int)((1.0 - ratio) * (float)c1.c.b + ratio * (float)c2.c.b),
			(int)((1.0 - ratio) * (float)c1.c.g + ratio * (float)c2.c.g),
			(int)((1.0 - ratio) * (float)c1.c.r + ratio * (float)c2.c.r),
			0}});
}
