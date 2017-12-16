/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_starbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:57:19 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/17 00:50:26 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	place_stars(t_vec4 *starbox)
{
	starbox[0] = (t_vec4) {100.0, -1000.0, 4000.0, 1.0};
	starbox[1] = (t_vec4) {2200.0, -1000.0, 4000.0, 1.0};
	starbox[2] = (t_vec4) {1000.0, -1500.0, 4000.0, 1.0};
	starbox[3] = (t_vec4) {-1000.0, -2000.0, 4000.0, 1.0};
	starbox[4] = (t_vec4) {-200.0, -2000.0, 4000.0, 1.0};
	starbox[5] = (t_vec4) {100.0, -1000.0, 3000.0, 1.0};
	starbox[6] = (t_vec4) {2200.0, -1000.0, 2800.0, 1.0};
	starbox[7] = (t_vec4) {1000.0, -1500.0, 3000.0, 1.0};
	starbox[8] = (t_vec4) {-1000.0, -2000.0, 2800.0, 1.0};
	starbox[9] = (t_vec4) {-200.0, 2000.0, 4000.0, 1.0};
	starbox[10] = (t_vec4) {100.0, 1000.0, 4000.0, 1.0};
	starbox[11] = (t_vec4) {1200.0, 1000.0, 4000.0, 1.0};
	starbox[12] = (t_vec4) {1000.0, -1500.0, 4000.0, 1.0};
	starbox[13] = (t_vec4) {-1000.0, -2000.0, 4000.0, 1.0};
	starbox[14] = (t_vec4) {-200.0, -2000.0, 4000.0, 1.0};
	starbox[15] = (t_vec4) {1700.0, -1000.0, 2800.0, 1.0};
	starbox[16] = (t_vec4) {2200.0, -3000.0, 4000.0, 1.0};
	starbox[17] = (t_vec4) {2000.0, -1500.0, 5000.0, 1.0};
	starbox[18] = (t_vec4) {-1000.0, -2000.0, 4000.0, 1.0};
	starbox[19] = (t_vec4) {-2900.0, -2000.0, 4000.0, 1.0};
	starbox[20] = (t_vec4) {1100.0, -1500.0, 2500.0, 1.0};
	starbox[21] = (t_vec4) {2200.0, -1000.0, 6000.0, 1.0};
	starbox[22] = (t_vec4) {1000.0, -1500.0, 3800.0, 1.0};
	starbox[23] = (t_vec4) {-1000.0, -2000.0, 4500.0, 1.0};
	starbox[24] = (t_vec4) {-200.0, -2000.0, 7000.0, 1.0};
}

void	init_starbox(t_map *map)
{
	map->starbox_size = 25;
	if (!(map->starbox = ft_memalloc(sizeof(t_vec4) * map->starbox_size)))
		error_exit("");
	if (!(map->starproj = ft_memalloc(sizeof(t_vec3) * map->starbox_size)))
		error_exit("");
	if (!(map->stardraw = ft_memalloc(sizeof(t_vec2c) * map->starbox_size)))
		error_exit("");
	place_stars(map->starbox);
}
