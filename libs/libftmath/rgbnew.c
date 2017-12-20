/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:10:31 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 21:14:56 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_rgb	rgbnew(unsigned char a, unsigned char r,
				unsigned char g, unsigned char b)
{
	t_rgb	new;

	new = (t_rgb) {a, r, g, b};
	return (new);
}
