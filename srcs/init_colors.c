/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:57:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 13:17:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_colorsets(t_colors *colors)
{
	if (!(colors->stock = ft_memalloc(sizeof(t_colorset) * 4)))
		error_exit("");
	(colors->stock[0]) = (t_colorset) { C_BLA, C_WHI, C_WHI, C_BLU };
}

void	init_colors(t_colors *colors)
{
	load_colorsets(colors);
	colors->active = colors->stock[0];
}
