/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbi_interi_ltd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:12:54 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 20:07:35 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

int	rgbi_interi_ltd(int c1, int c2, int distance, int progress)
{
	if (distance == 0)
		return (c2);
	if (progress > distance)
		return (c2);
	return (((MSK(c1 >> 16) + (progress * (MSK(c2 >> 16) - MSK(c1 >> 16)))
					/ distance) << 16)
			| ((MSK(c1 >> 8) + (progress * (MSK(c2 >> 8) - MSK(c1 >> 8)))
							/ distance) << 8)
			| ((MSK(c1) + (progress * (MSK(c2) - MSK(c1)))
							/ distance)));
}
