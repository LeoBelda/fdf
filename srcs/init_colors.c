/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:57:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 15:58:08 by lbelda           ###   ########.fr       */
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
	if (!(colors->disco = ft_memalloc(sizeof(t_colorset) * 8)))
		error_exit("");
	(colors->disco[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_WHI, C_GREEN_DARK };
	(colors->disco[1]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_GREEN_DARK, C_RED };
	(colors->disco[2]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_RED, C_PURPLE_DARK };
	(colors->disco[3]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_PURPLE_DARK, C_BLU };
	(colors->disco[4]) = (t_colorset) { C_WHI, C_PURPLE_DARK, C_PURPLE_DARK,
										C_GOLD_PALE, C_GRE };
	(colors->disco[5]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_GRE, C_BLU };
	(colors->disco[6]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
										C_GOLD_PALE, C_WHI };
	(colors->disco[7]) = (t_colorset) { 0, 0, 0, 0, 0 };
}

static void	load_program_daynight(t_colors *colors)
{
	if (!(colors->daynight = ft_memalloc(sizeof(t_colorset) * 7)))
		error_exit("");
	(colors->daynight[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
			   							C_WHI, C_GREEN_DARK };
	(colors->daynight[1]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
			   							C_GREEN_DARK, C_RED };
	(colors->daynight[2]) = (t_colorset) { C_WHI, C_ORANGE_DARK, C_ORANGE_DARK,
			   							C_RED, C_PURPLE_DARK };
	(colors->daynight[3]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
			   							C_PURPLE_DARK, C_BLU };
	(colors->daynight[4]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
			 		  					C_GOLD_PALE, C_PURPLE_DARK };
	(colors->daynight[5]) = (t_colorset) { C_WHI, C_ORANGE_DARK, C_ORANGE_DARK,
										C_WHI, C_PURPLE_DARK };
	(colors->daynight[6]) = (t_colorset) { 0, 0, 0, 0, 0 };
}

static void	load_program_blacknwhite(t_colors *colors)
{
	if (!(colors->blacknwhite = ft_memalloc(sizeof(t_colorset) * 7)))
		error_exit("");
	(colors->blacknwhite[0]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
			   							C_WHI, C_WHI };
	(colors->blacknwhite[1]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
			   							C_BLA, C_BLA };
	(colors->blacknwhite[2]) = (t_colorset) { C_WHI, C_BLA, C_BLA,
			   							C_WHI, C_WHI };
	(colors->blacknwhite[3]) = (t_colorset) { C_BLA, C_WHI, C_WHI,
			   							C_BLA, C_BLA };
	(colors->blacknwhite[4]) = (t_colorset) { C_BLA, C_BLA, C_BLA,
			 		  					C_WHI, C_WHI };
	(colors->blacknwhite[5]) = (t_colorset) { C_WHI, C_BLA, C_WHI,
										C_BLA, C_BLA };
	(colors->blacknwhite[6]) = (t_colorset) { 0, 0, 0, 0, 0 };
}

static void	set_cfuncs(t_colors *colors)
{
	if (!(colors->cfuncs = ft_memalloc(sizeof(t_cfuncs) * 5)))
		error_exit("");
	(colors->cfuncs)[0] = (t_cfuncs) { switch_colorset, C_STOCK };
	(colors->cfuncs)[1] = (t_cfuncs) { program_disco, C_DISCO };
	(colors->cfuncs)[2] = (t_cfuncs) { program_daynight, C_DAYNIGHT };
	(colors->cfuncs)[3] = (t_cfuncs) { program_blacknwhite, C_BLACKNWHITE };
	(colors->cfuncs)[4] = (t_cfuncs) { NULL, 0 };
}


void		init_colors(t_colors *colors)
{
	load_colorsets(colors);
	load_program_disco(colors);
	load_program_daynight(colors);
	load_program_blacknwhite(colors);
	set_cfuncs(colors);
	colors->active = colors->stock[0];
	colors->target = colors->stock[0];
	colors->from = colors->stock[0];
	colors->cmode = C_STOCK;
	colors->bufmode = B_DEFAULT;
}
