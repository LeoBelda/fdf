/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_progs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:04:22 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/16 14:42:48 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	program_disco(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->disco;
	if (i == 300)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->disco;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 300, i);
	i++;
}

void	program_hyper(t_colors *colors)
{
	static size_t		i;
	static t_colorset	*handle;

	if (!handle)
		handle = colors->hyper;
	if (i == 200)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->hyper;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 200, i);
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
	if (i == 60)
	{
		handle++;
		if (ft_ismemzero((void*)handle, sizeof(t_colorset)))
			handle = colors->glowing;
		colors->from = colors->active;
		colors->target = *handle;
		i = 0;
	}
	switch_colors(colors, 60, i);
	i++;
}
