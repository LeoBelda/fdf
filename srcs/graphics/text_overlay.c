/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_overlay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:14:18 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 23:46:49 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_fps_count(char *fps_str)
{
	static struct timespec	now;
	static int				i;
	struct timespec			tmp_time;
	static long int			fps_nb;

	ft_strclr(fps_str);
	if (i == 3)
	{
		tmp_time = now;
		clock_gettime(CLOCK_MONOTONIC, &now);
		fps_nb = lround(1.0 / 
				((((double)now.tv_sec + 1.0e-9 * now.tv_nsec) -
				((double)tmp_time.tv_sec + 1.0e-9 * tmp_time.tv_nsec)) / 3.0));
		i = 0;
	}
	ft_strcat(fps_str, "FPS : ");
	ft_strcat(fps_str, ft_itoa(fps_nb));
	i++;
}

void		manage_text_overlay(t_env *e)
{
	get_fps_count(e->overlay->fps);
	mlx_string_put(e->mlx, e->win, 10, 10,
					e->colors->active.text, e->overlay->fps);
}
