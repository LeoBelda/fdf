/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:54:30 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/16 13:26:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_map *map)
{
	if (map->infmode == INF_ON)
	{
		free(map->vertices);
		free(map->world_vtx);
	}
	free(map->mod_vertices);
	free(map->target_vtx_y);
	free(map->world_coords_glb);
	free(map->vertices_glb);
	free(map->m_world_vtx);
	free(map->distancesxy);
	free(map->distancesxz);
	free(map->proj);
	free(map->draw);
	free(map->clip);
	free(map->starfuncs);
	free(map->starbox);
	free(map->starproj);
	free(map->stardraw);
	free(map->dstfuncs);
	free(map->vdstfuncs);
	free(map);
}

static void	free_img_mat_col(t_img *img, t_matrices *mat, t_colors *col)
{
	int	i;

	i = -1;
	while (++i < NB_THRD)
		free(img->p_addr[i]);
	free(img->p_addr);
	free(img);
	free(mat->projs->stock);
	free(mat->projs);
	free(mat->views->stock);
	free(mat->views);
	free(mat);
	free(col->stock);
	free(col->disco);
	free(col->hyper);
	free(col->strobo);
	free(col->glowing);
	free(col->cfuncs);
	free(col->bfuncs);
	free(col);
}

static void	free_controls_overlay(t_controls *con, t_overlay *over)
{
	int	i;

	i = 0;
	while (con->presets[i].preset != NULL)
	{
		free(con->presets[i].preset);
		i++;
	}
	free(con->presets);
	free(con->kbsync);
	SDL_GameControllerClose(con->ps3);
	free(con);
	free(over->fps);
	free(over);
}

static void	free_sound(t_sound *sound)
{
	FMOD_RESULT	err;
	int			i;

	err = FMOD_OK;
	i = -1;
	if (sound->smode == S_ON)
	{
		free(sound->srfuncs);
		free(sound->scfuncs);
		while (++i < sound->data->numchannels)
			free(sound->data->oct[i]);
		free(sound->data->oct);
		free(sound->data->p_spec);
		free(sound->data);
		err |= FMOD_Channel_RemoveDSP(sound->channel, sound->fft);
		err |= FMOD_DSP_Release(sound->fft);
		err |= FMOD_Channel_Stop(sound->channel);
		err |= FMOD_Sound_Release(sound->song);
		err |= FMOD_System_Release(sound->system);
		if (err != FMOD_OK)
			ft_putendl("smthing wrong");
	}
	free(sound);
}

void		free_all_the_stuff(t_env *e)
{
	free_map(e->map);
	free_img_mat_col(e->img, e->matrices, e->colors);
	free_controls_overlay(e->controls, e->overlay);
	free_sound(e->sound);
	SDL_Quit();
	free(e);
}
