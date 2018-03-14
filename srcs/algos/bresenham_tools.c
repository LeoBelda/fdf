/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 20:27:36 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/14 15:37:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pix_clip(t_vec2c coord)
{
	if (coord.x < 0 || coord.x >= XWIN
	|| coord.y < 0 || coord.y >= YWIN)
		return (0);
	else
		return (1);
}

int	pix_clipr(t_vec2r coord)
{
	if (coord.x < 0 || coord.x >= XWIN
	|| coord.y < 0 || coord.y >= YWIN)
		return (0);
	else
		return (1);
}
