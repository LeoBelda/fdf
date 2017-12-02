/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_progs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:04:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/02 14:01:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	program_strobo(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->strobo;
	if (i == 40)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->strobo;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 40, i);
	i++;
}

void	program_glowing(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->glowing;
	if (i == 90)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->glowing;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 90, i);
	i++;
}
