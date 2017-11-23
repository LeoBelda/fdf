/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_overlay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:14:18 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 23:40:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_fps_count(void)
{
	static double	times[10];
	char			*fps;

	(void)times;
	fps = ft_strnew(15);
	ft_strcat(fps, "FPS : ");
	return (fps);
}

void		manage_text_overlay(t_env *e)
{
	char	*fps_count;

	fps_count = get_fps_count();
	mlx_string_put(e->mlx, e->win, 10, 10, C_WHIT, fps_count);
	ft_strdel(&fps_count);
}
