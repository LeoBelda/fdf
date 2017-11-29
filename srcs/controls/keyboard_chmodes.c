/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chmodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:41:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 23:01:07 by lbelda           ###   ########.fr       */
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

static void	set_to_bird(t_matrices *matrices)
{
	t_vec4	tmp;

	tmp = get_eye_pos(matrices->views->active);
	matrices->eye_pos = mat4xvec4(trsmat4new(0.0, 0.0, 4000.0),
								vec4new(tmp.x, tmp.z, 0.0, 1.0));
	print_vec4(matrices->eye_pos);
	ft_putendl("");
	matrices->views->target = get_view_mat(matrices->eye_pos,
				mat4xvec4(trsmat4new(0.0, -50.0, 0.0), matrices->eye_pos),
				vec4new(0.0, 0.0, 1.0, 0.0));
}

static void	set_to_fox(t_matrices *matrices, double mid_height)
{
	t_vec4	tmp;

	tmp = get_eye_pos(matrices->views->active);
	matrices->eye_pos = mat4xvec4(trsmat4new(0.0, -mid_height * 2.0, 0.0),
								vec4new(tmp.x, 0.0, tmp.z, 1.0));
	matrices->views->target = get_view_mat(matrices->eye_pos,
				mat4xvec4(trsmat4new(0.0, 0.0, 50.0), matrices->eye_pos),
						vec4new(0.0, 1.0, 0.0, 0.0));
}

void	k_chpov(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->matrices->projs->stock_size;
	e->mode = (e->mode == M_SKY ? M_GRD : M_SKY);
	e->matrices->views->from = e->matrices->views->active;
	if (e->mode == M_SKY)
		set_to_bird(e->matrices);
	else
		set_to_fox(e->matrices, e->map->mid_height);
	ft_bzero(&(e->matrices->movement), sizeof(t_modmat));
	e->matrices->movement.s = 1.0;
	e->matrices->views->progress = 0;
	e->matrices->views->switching = 1;
	e->matrices->projs->from = e->matrices->projs->active;
	e->matrices->projs->progress = 0;
	e->matrices->projs->switching = 1;
	e->matrices->projs->target = e->matrices->projs->stock[i];
}
