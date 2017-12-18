/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbi_5blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:54:42 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/14 16:35:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshader.h"

t_rgb	rgb_xblend(t_rgb *colors, float ratio, int x)
{
	int		i;

	i = (ratio * (float)(x - 1));
	ratio = fmodf(ratio, 1.0 / (float)(x - 1)) * (float)(x - 1);
	return (rgb_mix(colors[i], colors[i + 1], ratio));
}
