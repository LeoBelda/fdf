/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbi_interi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 04:33:03 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 05:03:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

int	rgbi_interi(int c1, int c2, int distance, int progress)
{

	if (distance == 0)
		return (c1);
	return (((MSK(c1 >> 16) + (progress * (MSK(c2 >> 16) - MSK(c1 >> 16)))
					/ distance) << 16)
	      | ((MSK(c1 >> 8) + (progress * (MSK(c2 >> 8) - MSK(c1 >> 8)))
					/ distance) << 8)
	      | ((MSK(c1) + (progress * (MSK(c2) - MSK(c1)))
					/ distance)));
}
