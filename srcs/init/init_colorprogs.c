/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colorprogs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:14:05 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:20:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_program_disco(t_colors *colors)
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

void	load_program_daynight(t_colors *colors)
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

void	load_program_blacknwhite(t_colors *colors)
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
