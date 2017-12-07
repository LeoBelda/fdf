/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chmodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:41:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/07 01:49:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		k_chspace(t_env *e, int flag)
{
	if (flag == 0)
		return ;
	e->matrices->projs->gmode.pmode =
		(e->matrices->projs->gmode.pmode == P_DEFAULT ? P_SPACE : P_DEFAULT);
}

static void	set_to_bird(t_matrices *matrices)
{
	t_vec4	tmp;
	size_t	i;

	i = 0;
	tmp = get_eye_pos(matrices->views->active);
	matrices->eye_pos = mat4xvec4(trsmat4new(0.0, 0.0, 2000.0),
								vec4new(tmp.x, tmp.z, 0.0, 1.0));
	while (matrices->views->stock[i].gmode.vmode)
	{
		if (matrices->views->stock[i].gmode.vmode == V_SKY)
		{
			matrices->views->stock[i].mat = get_view_mat(matrices->eye_pos,
				mat4xvec4(trsmat4new(0.0, -50.0, 0.0), matrices->eye_pos),
				vec4new(0.0, 0.0, 1.0, 0.0));
			break;
		}
		i++;
	}
	matrices->views->gmode.vmode = V_SKY;
	matrices->projs->gmode.pmode = P_SKY;
}

static void	set_to_fox(t_matrices *matrices, t_vec4 mid_mod)
{
	t_vec4	tmp;
	size_t	i;

	i = 0;
	tmp = get_eye_pos(matrices->views->active);
	matrices->eye_pos = mat4xvec4(trsmat4new(0.0, 0.0, 0.0),
								vec4new(tmp.x, mid_mod.y, tmp.z, 1.0));
	while (matrices->views->stock[i].gmode.vmode)
	{
		if (matrices->views->stock[i].gmode.vmode == V_GRD)
		{
			matrices->views->stock[i].mat = get_view_mat(matrices->eye_pos,
				mat4xvec4(trsmat4new(0.0, 0.0, 50.0), matrices->eye_pos),
						vec4new(0.0, 1.0, 0.0, 0.0));
			break;
		}
		i++;
	}
	matrices->views->gmode.vmode = V_GRD;
	matrices->projs->gmode.pmode = P_DEFAULT;
}

void		k_chpov(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->matrices->projs->stock_size;
	e->mode = (e->mode == M_SKY ? M_GRD : M_SKY);
	switch_kbmode(e, &e->controls->active, KB_SWI);
	switch_kbmode(e, &e->controls->target,
					get_mode_sync(e->controls->kbsync, e->mode));
	e->matrices->views->from = e->matrices->views->active;
	if (e->mode == M_SKY)
		set_to_bird(e->matrices);
	else
		set_to_fox(e->matrices, e->map->mid_mod);
	ft_bzero(&(e->matrices->movement), sizeof(t_modmat));
	e->matrices->movement.s = 1.0;
}
