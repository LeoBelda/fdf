/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:08:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 15:55:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int min_z, int max_z, int z, t_colorset active)
{
	return (rgbi_interi(active.bottom, active.top, max_z - min_z,
												z - min_z));
}

void	switch_colorset(t_colors *colors)
{
	size_t	j;
	int		*handle_act;
	int		*handle_tar;
	int		*handle_from;

	if (!ft_memcmp((void*)&(colors->active),
				   (void*)&(colors->target), sizeof(t_colorset)))
	{
		colors->progress = 0;
		return ;
	}
	j = 0;
	handle_act = &colors->active.text;
	handle_tar = &colors->target.text;
	handle_from = &colors->from.text;
	while (&(handle_tar[j]) <= &colors->target.top)
	{
		handle_act[j] = rgbi_interi(handle_from[j], handle_tar[j],
									100, colors->progress);
		j++;
	}
	colors->progress++;
}

void	switch_colors(t_colors *colors, size_t distance, size_t progress)
{
	size_t	j;

	j = 0;
	if (!ft_memcmp((void*)&(colors->active),
				   (void*)&(colors->target), sizeof(t_colorset)))
		return ;
	while (&((&colors->target.text)[j])<= &colors->target.top)
	{
		(&colors->active.text)[j] = rgbi_interi((&colors->from.text)[j],
							(&colors->target.text)[j], distance, progress);
		j++;
	}
}

void	program_disco(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->disco;
	if (i == 20)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->disco;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 20, i);
	i++;
}

void	program_daynight(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->daynight;
	if (i == 600)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->daynight;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 600, i);
	i++;

}

void	program_blacknwhite(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->blacknwhite;
	if (i == 40)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->blacknwhite;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 40, i);
	i++;

}
