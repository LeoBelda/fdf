/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:08:30 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/17 23:34:30 by lbelda           ###   ########.fr       */
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
	while (&(handle_tar[j]) <= &colors->target.st3)
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
	while (&((&colors->target.text)[j]) <= &colors->target.st3)
	{
		(&colors->active.text)[j] = rgbi_interi((&colors->from.text)[j],
							(&colors->target.text)[j], distance, progress);
		j++;
	}
}
