/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:05:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 13:36:42 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham1(t_vec2r a, t_vec2r b, t_img imginf)
{
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
		imginf.addr[a.x + a.y * XWIN] = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y++;
			e -= 1.0;
		}
		a.x++;
	}
}

static void	bresenham2(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		dx;
	int		dy;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = fabs((double)dy / (double)dx);
	e = -0.5;
	while (a.x <= b.x)
	{
		imginf.addr[a.x + a.y * XWIN] = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y--;
			e -= 1.0;
		}
		a.x++;
	}
}

static void	bresenham3(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		dx;
	int		dy;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = (double)dx / (double)dy;
	e = -0.5;
	while (a.y <= b.y)
	{
		imginf.addr[a.x + a.y * XWIN] = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y++;
	}
}

static void	bresenham4(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		dx;
	int		dy;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = fabs((double)dx / (double)dy);
	e = -0.5;
	while (a.y >= b.y)
	{
		imginf.addr[a.x + a.y * XWIN] = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y--;
	}
}

void	draw_line(t_vec2r a, t_vec2r b, t_img imginf)
{
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (b.x > a.x)
			//oct 1 - 8
			b.y > a.y ? bresenham1(a, b, imginf) : bresenham2(a, b, imginf);
		else
			//oct 5 - 4
			b.y > a.y ? bresenham2(b, a, imginf) : bresenham1(b, a, imginf);
	}
	else
	{
		if (b.x > a.x)
			//oct 2 - 7
			b.y > a.y ? bresenham3(a, b, imginf) : bresenham4(a, b, imginf);
		else
			//oct 6 - 3
			b.y > a.y ? bresenham4(b, a, imginf) : bresenham3(b, a, imginf);
	}
}


