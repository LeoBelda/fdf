/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chmodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:41:27 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 23:23:14 by lbelda           ###   ########.fr       */
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

void	k_chpov(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	i = (i + 1) % e->matrices->views->stock_size;
	e->matrices->views->from = e->matrices->views->active;
	e->matrices->views->progress = 0;
	e->matrices->views->switching = 1;
	e->matrices->views->target = e->matrices->views->stock[i];
	e->matrices->projs->from = e->matrices->projs->active;
	e->matrices->projs->progress = 0;
	e->matrices->projs->switching = 1;
	e->matrices->projs->target = e->matrices->projs->stock[i];
}
