/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_distfuncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:50:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/05 19:17:17 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dstfuncs(t_map *map)
{
	if (!(map->dstfuncs = ft_memalloc(sizeof(t_dstfuncs) * 3)))
		error_exit("");
	(map->dstfuncs)[0] = (t_dstfuncs) { dst_default, DST_DEFAULT };
	(map->dstfuncs)[1] = (t_dstfuncs) { dst_around_flat, DST_AROUND_FLAT };
	(map->dstfuncs)[2] = (t_dstfuncs) { NULL, 0 };
}
