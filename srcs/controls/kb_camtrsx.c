/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_camtrsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:30:08 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:30:33 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? 10 : 0.0);
}

void	k_trscamrx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? -10 : 0.0);
}
