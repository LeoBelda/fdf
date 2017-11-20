/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:05:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 15:28:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham1(t_vec2r a, t_vec2r b, int incx, int incy, t_img imginf)
{
	int		*intaddr;
	int		dx;
	int		dy;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = (double)dy / (double)dx;
	e = -0.5;
	while (a.x <= b.x)
	{
			intaddr = (int*)&(imginf.addr[a.x * (imginf.bpp / 8) + a.y * imginf.size_line]);
			*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y += incy;
			e -= 1.0;
		}
		a.x += incx;
	}
}

void	bresenham2(t_vec2r a, t_vec2r b, int incx, int incy, t_img imginf)
{
	int		*intaddr;
	int		dx;
	int		dy;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = (double)dy / (double)dx;
	e = -0.5;
	while (a.x <= b.x)
	{
			intaddr = (int*)&(imginf.addr[a.y * (imginf.bpp / 8) + a.x * imginf.size_line]);
			*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y += incy;
			e -= 1.0;
		}
		a.x += incx;
	}
}
