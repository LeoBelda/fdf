/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:57:20 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/17 14:29:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	load_colorsets(t_colors *colors)
{
	colors->stock_size = 5;
	if (!(colors->stock = ft_memalloc(sizeof(t_colorset) *
										colors->stock_size)))
		error_exit("");
	(colors->stock[1]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_GOLD_PALE, C_BLU,
										C_WHI, C_BLU, C_LIGHT_RED};
	(colors->stock[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_WHI, C_WHI,
										C_WHI, C_BLU, C_LIGHT_RED};
	(colors->stock[2]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
										C_BLA, C_BLA,
										C_BLA, C_RED, C_RED};
	(colors->stock[3]) = (t_colorset) { C_BLA, C_GOLD_PALE, C_WHI,
										C_BLU, C_RED,
										C_RED, C_BLU, C_GOLD_PALE};
	(colors->stock[4]) = (t_colorset) { C_BLA, C_GOLD_PALE, C_WHI,
										C_BROWNIE, C_GRE,
										C_PURPLE_DARK, C_BLU, C_GOLD_PALE};
}

void		init_colors(t_colors *colors)
{
	load_colorsets(colors);
	load_program_disco(colors);
	load_program_hyper(colors);
	load_program_strobo(colors);
	load_program_glowing(colors);
	set_cfuncs(colors);
	set_bfuncs(colors);
	colors->active = colors->stock[0];
	colors->target = colors->stock[0];
	colors->from = colors->stock[0];
}
