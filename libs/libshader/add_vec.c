/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 02:09:44 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/12 02:10:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshader.h"

t_vec3pf	add_vec(t_vec3pf v1, t_vec3pf v2)
{
	return ((t_vec3pf) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}
