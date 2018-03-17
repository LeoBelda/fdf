/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colorprogs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:14:05 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/17 14:44:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_program_disco(t_colors *colors)
{
	if (!(colors->disco = ft_memalloc(sizeof(t_colorset) * 8)))
		error_exit("");
	(colors->disco[0]) = (t_colorset) { C_WHI, C_GOLD_PALE, C_BLA,
										C_WHI, C_GREEN_DARK,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->disco[1]) = (t_colorset) { C_WHI, C_AQUAMARINE, C_BLA,
										C_BLU, C_RED,
										C_GREEN_DARK, C_BLU, C_GOLD_PALE};
	(colors->disco[2]) = (t_colorset) { C_WHI, C_BLUE_NAVY, C_BLA,
										C_RED, C_RED,
										C_GRE, C_BLU, C_GOLD_PALE};
	(colors->disco[3]) = (t_colorset) { C_WHI, C_PURPLE_DARK, C_BLA,
										C_PURPLE_DARK, C_BLU,
										C_RED, C_BLU, C_GOLD_PALE};
	(colors->disco[4]) = (t_colorset) { C_WHI, C_GOLD_PALE, C_BLA,
										C_GRE, C_GRE,
										C_BLU, C_BLU, C_GOLD_PALE};
	(colors->disco[5]) = (t_colorset) { C_WHI, C_LIGHT_RED, C_BLA,
										C_GRE, C_BLU,
										C_GRE, C_BLU, C_GOLD_PALE};
	(colors->disco[6]) = (t_colorset) { C_WHI, C_WHI, C_BLA,
										C_GOLD_PALE, C_WHI,
										C_RED, C_BLU, C_GOLD_PALE};
	(colors->disco[7]) = (t_colorset) { 0, 0, 0, 0, 0, 0, 0, 0 };
}

void	load_program_hyper(t_colors *colors)
{
	if (!(colors->hyper = ft_memalloc(sizeof(t_colorset) * 7)))
		error_exit("");
	(colors->hyper[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_WHI, C_GREEN_DARK,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->hyper[1]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_GREEN_DARK, C_GREEN_DARK,
										C_GOLD_PALE, C_RED, C_GRE};
	(colors->hyper[2]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_RED, C_PURPLE_DARK,
										C_WHI, C_PURPLE_DARK, C_RED};
	(colors->hyper[3]) = (t_colorset) { C_BLA, C_BLA, C_WHI,
										C_WHI, C_RED,
										C_GOLD_PALE, C_GRE, C_GOLD_PALE};
	(colors->hyper[4]) = (t_colorset) { C_BLA, C_BLA, C_WHI,
										C_GOLD_PALE, C_ORANGE_DARK,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->hyper[5]) = (t_colorset) { C_WHI, C_BLA, C_ORANGE_DARK,
										C_WHI, C_WHI,
										C_GOLD_PALE, C_BROWNIE, C_GOLD_PALE};
	(colors->hyper[6]) = (t_colorset) { 0, 0, 0, 0, 0, 0, 0, 0 };
}

void	load_program_strobo(t_colors *colors)
{
	if (!(colors->strobo = ft_memalloc(sizeof(t_colorset) * 7)))
		error_exit("");
	(colors->strobo[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
											C_WHI, C_WHI,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[1]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
											C_BLA, C_BLA,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[2]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
											C_WHI, C_WHI,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[3]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
											C_BLA, C_BLA,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[4]) = (t_colorset) { C_BLA, C_BLA, C_BLA,
											C_WHI, C_WHI,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[5]) = (t_colorset) { C_WHI, C_BLA, C_WHI,
											C_BLA, C_BLA,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->strobo[6]) = (t_colorset) { 0, 0, 0, 0, 0, 0, 0, 0 };
}

void	load_program_glowing(t_colors *colors)
{
	if (!(colors->glowing = ft_memalloc(sizeof(t_colorset) * 4)))
		error_exit("");
	(colors->glowing[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
											C_BLA, C_RED,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->glowing[1]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
											C_BLA, C_RED,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->glowing[2]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
											C_BLA, C_BLA,
										C_WHI, C_BLU, C_GOLD_PALE};
	(colors->glowing[3]) = (t_colorset) { 0, 0, 0, 0, 0, 0, 0, 0 };
}
