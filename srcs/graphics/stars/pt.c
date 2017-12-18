/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 23:18:15 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/17 23:33:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dw_pt(t_vec2r point, t_cmix cl, int *addr)
{
	if (pix_clipr(point))
		addr[point.x + point.y * XWIN] =
			rgb_mix((t_rgb)cl.a, (t_rgb)cl.b, cl.r).i;
}
