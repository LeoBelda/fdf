/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:57:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/30 23:19:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	load_colorsets(t_colors *colors)
{
	colors->stock_size = 4;
	if (!(colors->stock = ft_memalloc(sizeof(t_colorset) *
										colors->stock_size)))
		error_exit("");
	(colors->stock[0]) = (t_colorset) { C_WHI, C_BLA, C_WHI,
										C_RED, C_WHI };
	(colors->stock[1]) = (t_colorset) { C_WHI, C_BLU, C_BLA,
										C_WHI, C_WHI };
	(colors->stock[2]) = (t_colorset) { C_BLA, C_RED, C_WHI,
										C_BLA, C_WHI };
	(colors->stock[3]) = (t_colorset) { C_WHI, C_BLU, C_WHI,
										C_WHI, C_WHI };
}

static void	load_program_disco(t_colors *colors)
{
	if (!(colors->disco = ft_memalloc(sizeof(t_colorset) *
										colors->stock_size)))
		error_exit("");
	(colors->disco[0]) = (t_colorset) { C_WHI, C_BLA, C_WHI,
										C_RED, C_WHI };
	(colors->disco[1]) = (t_colorset) { C_WHI, C_BLU, C_BLA,
										C_WHI, C_WHI };
	(colors->disco[2]) = (t_colorset) { C_WHI, C_BLA, C_WHI,
										C_BLA, C_WHI };
	(colors->disco[3]) = (t_colorset) { C_WHI, C_RED, C_WHI,
										C_WHI, C_WHI };
	(colors->disco[4]) = (t_colorset) { C_BLA, C_BLA, C_BLA,
										C_BLA, C_BLA };
}

void		init_colors(t_colors *colors)
{
	load_colorsets(colors);
	load_program_disco(colors);
	colors->active = colors->stock[0];
	colors->target = colors->stock[0];
	colors->from = colors->stock[0];
	colors->mode = C_STOCK;
}
