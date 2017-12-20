/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4f_to_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:08:43 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 23:27:17 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshader.h"

int		vec4cf_to_rgb(t_vec4cf color)
{
	t_vec4c	rgb;

	rgb.argb.b = (unsigned char)(color.b * 255.0);
	rgb.argb.g = (unsigned char)(color.g * 255.0);
	rgb.argb.r = (unsigned char)(color.r * 255.0);
	rgb.argb.a = (unsigned char)(color.a * 255.0);
	return (rgb.val);
}
