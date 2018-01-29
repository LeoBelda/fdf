/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtcore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:03:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 09:44:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	rmloop(t_vec3pf or, t_vec3pf tr)
{
	int			i;
	float		dist;
	t_vec3pf	ray;

	i = -1;
	ray = or;
	while (++i < 32)
	{
		dist = sdf_sphere(ray);
		if (dist < 0.01)
			break ;
		ray = add_vec(ray, scal_vec(tr, dist));
	}
	return (step(10.0, vec_length(sub_vec(or, ray))));
}

static int	shader(t_vec2r fragcoords, t_vec2f fres)
{
	float	col;
	t_vec2f	uv;

	(void)fres;
	uv = (t_vec2f) {((float)fragcoords.x) / 2560.0,
						((float)fragcoords.y) / 1440.0};
	uv.x = uv.x * 2.0 - 1.0;
	uv.y = uv.y * 2.0 - 1.0;
	uv.x *= (2560.0 / 1440.0);
	col = rmloop((t_vec3pf) {0.0, 0.0, -3.0},
				vec_normalize((t_vec3pf) {uv.x, uv.y, 1.0}));
	return (vec4cf_to_rgb((t_vec4cf) { 0.2, 0.0, 1 - col, 0.0}));
}

static void	rtcore(int *addr)
{
	t_vec2r	frag_coords;
	t_vec2r	res;
	t_vec2f	fres;

	res = (t_vec2r) { XWIN, YWIN };
	fres = (t_vec2f) { X_WIN, Y_WIN };
	frag_coords.y = -1;
	while (++frag_coords.y < YWIN)
	{
		frag_coords.x = -1;
		while (++frag_coords.x < XWIN)
			addr[frag_coords.x + frag_coords.y * XWIN] =
					shader(frag_coords, fres);
	}
}

int			rtinit(t_env *e)
{
	rtcore(e->img->addr);
	if (mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0) == -1)
		error_exit("Failed to display image");
	manage_text_overlay(e);
	return (0);
}
