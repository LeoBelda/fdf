/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_clip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 20:25:23 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 19:31:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham1(t_vec2c a, t_vec2c b, t_img imginf)
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
		if (pix_clip(a))
			ft_intcpy(&(imginf.addr[a.x + a.y * XWIN]),
					rgb_to_int(rgb_interi(a.color, b.color, dx, i)));
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

static void	bresenham2(t_vec2c a, t_vec2c b, t_img imginf)
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
		if (pix_clip(a))
			ft_intcpy(&(imginf.addr[a.x + a.y * XWIN]),
					rgb_to_int(rgb_interi(a.color, b.color, dx, i)));
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

static void	bresenham3(t_vec2c a, t_vec2c b, t_img imginf)
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
		if (pix_clip(a))
			ft_intcpy(&(imginf.addr[a.x + a.y * XWIN]),
					rgb_to_int(rgb_interi(a.color, b.color, dy, i)));
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

static void	bresenham4(t_vec2c a, t_vec2c b, t_img imginf)
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
		if (pix_clip(a))
			ft_intcpy(&(imginf.addr[a.x + a.y * XWIN]),
					rgb_to_int(rgb_interi(a.color, b.color, -dy, i)));
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

void	draw_clipline(t_vec2c a, t_vec2c b, t_img imginf)
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


