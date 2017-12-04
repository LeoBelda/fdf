/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_chcolors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:56:47 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/04 15:14:38 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_chcolor_stock(t_env *e, int flag)
{
	static size_t	i;

	if (flag == 0)
		return ;
	e->colors->cmode = C_STOCK;
	i = (i + 1) % e->colors->stock_size;
	e->colors->from = e->colors->active;
	e->colors->progress = 0;
	e->colors->target = e->colors->stock[i];
}

void	k_chcolor_program(t_env *e, int flag)
{
	if (flag == 0)
		return ;
	if (++(e->colors->cmode) == C_LAST)
	{
		e->colors->cmode = C_STOCK;
		e->colors->from = e->colors->active;
		e->colors->target = e->colors->stock[0];
	}
	e->colors->progress = 0;
}

void	k_chbuff_mode(t_env *e, int flag)
{
	if (flag == 0)
		return ;
	if (++(e->colors->bufmode) == B_LAST)
		e->colors->bufmode = B_DEFAULT;
}
