/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:05:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 18:44:58 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham1(t_vec2r a, t_vec2r b, t_img imginf)
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

static void	bresenham2(t_vec2r a, t_vec2r b, t_img imginf)
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

static void	bresenham3(t_vec2r a, t_vec2r b, t_img imginf)
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

static void	bresenham4(t_vec2r a, t_vec2r b, t_img imginf)
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

void	draw_line(t_vec4 a, t_vec4 b, t_img imginf)
{
	t_vec2r	ar;
	t_vec2r	br;

	ar = vec2rnewd(a.x, a.y);
	br = vec2rnewd(b.x, b.y);
	if (fabs(b.x - a.x) > fabs(b.y - a.y))
	{
		if (br.x > ar.x)
			//oct 1 - 8
			br.y > ar.y ? bresenham1(ar, br, imginf) : bresenham2(ar, br, imginf);
		else
			//oct 5 - 4
			br.y > ar.y ? bresenham2(br, ar, imginf) : bresenham1(br, ar, imginf);
	}
	else
	{
		if (br.x > ar.x)
			//oct 2 - 7
			br.y > ar.y ? bresenham3(ar, br, imginf) : bresenham4(ar, br, imginf);
		else
			//oct 6 - 3
			br.y > ar.y ? bresenham4(br, ar, imginf) : bresenham3(br, ar, imginf);
	}
}


