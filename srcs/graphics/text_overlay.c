/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_overlay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:14:18 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 13:32:06 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_fps_count(void)
{
	static struct timespec	now;
	static int				i;
	struct timespec			tmp_time;
	char					*fps_str;
	static long int			fps_nb;

	if (i == 3)
	{
		tmp_time = now;
		clock_gettime(CLOCK_MONOTONIC, &now);
		fps_nb = lround(1.0 / 
				((((double)now.tv_sec + 1.0e-9 * now.tv_nsec) -
				((double)tmp_time.tv_sec + 1.0e-9 * tmp_time.tv_nsec)) / 3.0));
		i = 0;
	}
	if (!(fps_str = ft_strnew(20)))
		error_exit("");
	ft_strcat(fps_str, "FPS : ");
	ft_strcat(fps_str, ft_itoa(fps_nb));
	i++;
	return (fps_str);
}

void		manage_text_overlay(t_env *e)
{
	char	*fps_count;

	fps_count = get_fps_count();
	mlx_string_put(e->mlx, e->win, 10, 10, C_WHIT, fps_count);
	ft_strdel(&fps_count);
}
