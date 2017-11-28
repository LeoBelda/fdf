/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chmodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:41:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 23:31:56 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_chcolor(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->colors->stock_size;
	e->colors->from = e->colors->active;
	e->colors->progress = 0;
	e->colors->target = e->colors->stock[i];
}

static t_mat4	set_to_bird(t_mat4 active)
{
	print_mat4(active);
	return (get_view_mat(
					vec4new(-active.w.x, -1950.0, -active.w.z, 1.0),
						vec4new(-active.w.x, -2000.0, -active.w.z, 1.0),
						vec4new(0.0, 0.0, 1.0, 0.0)));
}

static t_mat4	set_to_fox(t_mat4 active, double mid_height)
{
	return (
			get_view_mat(vec4new(-active.w.x, -mid_height * 1.6, -active.w.y, 1.0),
						mat4xvec4(trsmat4new(0.0, 0.0, 50.0),
								vec4new(-active.w.x, -mid_height * 1.6, -active.w.y, 1.0)),
						vec4new(0.0, 1.0, 0.0, 0.0)));
}

void	k_chpov(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->matrices->views->stock_size;
	e->mode = (e->mode == M_SKY ? M_GRD : M_SKY);
	e->matrices->views->from = e->matrices->views->active;
	if (e->mode == M_SKY)
		e->matrices->views->target = set_to_bird(e->matrices->views->active);
	else
		e->matrices->views->target = set_to_fox(e->matrices->views->active,
											e->map->mid_height);

	ft_bzero(&(e->matrices->movement), sizeof(t_modmat));
	e->matrices->movement.s = 1.0;
	e->matrices->views->progress = 0;
	e->matrices->views->switching = 1;
	e->matrices->projs->from = e->matrices->projs->active;
	e->matrices->projs->progress = 0;
	e->matrices->projs->switching = 1;
	e->matrices->projs->target = e->matrices->projs->stock[i];
}
