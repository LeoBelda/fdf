/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:57:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 21:18:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	load_colorsets(t_colors *colors)
{
	colors->stock_size = 4;
	if (!(colors->stock = ft_memalloc(sizeof(t_colorset) *
										colors->stock_size)))
		error_exit("");
	(colors->stock[0]) = (t_colorset) { C_WHI, C_BLA,
										C_RED, C_WHI };
	(colors->stock[1]) = (t_colorset) { C_WHI, C_BLU,
										C_WHI, C_WHI };
	(colors->stock[2]) = (t_colorset) { C_BLA, C_RED,
										C_BLA, C_WHI };
	(colors->stock[3]) = (t_colorset) { C_WHI, C_BLU,
										C_WHI, C_WHI };
}

void		init_colors(t_colors *colors)
{
	load_colorsets(colors);
	colors->active = colors->stock[0];
	colors->target = colors->stock[0];
	colors->from = colors->stock[0];
}
