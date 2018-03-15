/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2rnewi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:44:44 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 19:01:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec2r	vec2rnewi(int x, int y)
{
	t_vec2r	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}