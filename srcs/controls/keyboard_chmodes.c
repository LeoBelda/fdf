/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chmodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:41:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 17:08:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_chcolor(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->colors->stock_size;
	e->colors->from = e->colors->active;
	e->colors->progress = 0;
	e->colors->target = e->colors->stock[i];
}
