/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:05:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/20 16:44:24 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham1(t_vec2r a, t_vec2r b, t_img imginf)
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
		intaddr = (int*)&(imginf.addr
						[a.x * (imginf.bpp / 8) + a.y * imginf.size_line]);
		*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y++;
			e -= 1.0;
		}
		a.x++;
	}
}

void	bresenham2(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		*intaddr;
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
			intaddr = (int*)&(imginf.addr[a.x * (imginf.bpp / 8) + a.y * imginf.size_line]);
			*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.y--;
			e -= 1.0;
		}
		a.x++;
	}
}

void	bresenham3(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		*intaddr;
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
		intaddr = (int*)&(imginf.addr
						[a.x * (imginf.bpp / 8) + a.y * imginf.size_line]);
		*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y++;
	}
}

void	bresenham4(t_vec2r a, t_vec2r b, t_img imginf)
{
	int		*intaddr;
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
		intaddr = (int*)&(imginf.addr
						[a.x * (imginf.bpp / 8) + a.y * imginf.size_line]);
		*intaddr = C_CYAN;
		e += m;
		if (e >= 0.0)
		{
			a.x++;
			e -= 1.0;
		}
		a.y--;
	}
}
