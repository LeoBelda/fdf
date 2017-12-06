/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:36:00 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 19:13:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_exit(t_env *e, int flag)
{
	if (flag == 0)
		return ;
	if (mlx_destroy_image(e->mlx, e->img->img) == -1)
		error_exit("Failed to destroy image");
	exit(0);
}
