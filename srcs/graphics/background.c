/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:16:00 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 13:00:14 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*plain_background(void *dt)
{
	long int	longcolor;
	t_thrdbuf		*d;

	d = (t_thrdbuf*)dt;
	ft_intset(&longcolor, d->color, 2);
	ft_lintset(&(d->addr[d->i * XWIN * YWIN / NB_THRD]),
			longcolor, XWIN * YWIN / (2 * NB_THRD));
	return (NULL);
}

void	*no_background(void *dt)
{
	(void)dt;
	return (NULL);
}
