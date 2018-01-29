/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:05:48 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 13:51:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham1(t_vec2c a, t_vec2c b, int *addr)
{
	int		dx;
	int		dy;
	int		i;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = (double)dy / (double)dx;
	e = -0.5;
	i = 0;
	while (a.x <= b.x)
	{
		if (addr[a.x + a.y * XWIN] <= a.color)
			addr[a.x + a.y * XWIN] = rgbi_interi(a.color, b.color, dx, i);
		e += m;
		if (e >= 0.0)
		{
			a.y++;
			e -= 1.0;
		}
		a.x++;
		i++;
	}
}

static void	bresenham2(t_vec2c a, t_vec2c b, int *addr)
{
	int		dx;
	int		dy;
	int		i;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = fabs((double)dy / (double)dx);
	e = -0.5;
	i = 0;
	while (a.x <= b.x)
	{
		if (addr[a.x + a.y * XWIN] <= a.color)
			addr[a.x + a.y * XWIN] = rgbi_interi(a.color, b.color, dx, i);
		e += m;
		if (e >= 0.0)
		{
			a.y--;
			e -= 1.0;
		}
		a.x++;
		i++;
	}
}

static void	bresenham3(t_vec2c a, t_vec2c b, int *addr)
{
	int		dx;
	int		dy;
	int		i;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = (double)dx / (double)dy;
	e = -0.5;
	i = 0;
	while (a.y <= b.y)
	{
		if (addr[a.x + a.y * XWIN] <= a.color)
			addr[a.x + a.y * XWIN] = rgbi_interi(a.color, b.color, dy, i);
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y++;
		i++;
	}
}

static void	bresenham4(t_vec2c a, t_vec2c b, int *addr)
{
	int		dx;
	int		dy;
	int		i;
	double	m;
	double	e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = fabs((double)dx / (double)dy);
	e = -0.5;
	i = 0;
	while (a.y >= b.y)
	{
		if (addr[a.x + a.y * XWIN] <= a.color)
			addr[a.x + a.y * XWIN] = rgbi_interi(a.color, b.color, -dy, i);
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y--;
		i++;
	}
}

/*
** BRESENHAM : 1 and 2 (a,b) for quadrants 1/8
**			   2 and 1 (b,a) for quadrants 5/4
**			   3 and 4 (a,b) for quadrants 2/7
**			   4 and 3 (b,a) for quadrants 6/3
*/

void		bresenham(t_vec2c a, t_vec2c b, int *addr)
{
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (b.x > a.x)
			b.y > a.y ? bresenham1(a, b, addr) : bresenham2(a, b, addr);
		else
			b.y > a.y ? bresenham2(b, a, addr) : bresenham1(b, a, addr);
	}
	else
	{
		if (b.x > a.x)
			b.y > a.y ? bresenham3(a, b, addr) : bresenham4(a, b, addr);
		else
			b.y > a.y ? bresenham4(b, a, addr) : bresenham3(b, a, addr);
	}
}
