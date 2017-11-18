/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:52:15 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 17:32:38 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_parsed_map(t_list *vertices)
{
	while (vertices)
	{
		printf("x: %f  y: %f  z: %f  w: %f\n",
				((t_vec4*)(vertices->content))->x,
				((t_vec4*)(vertices->content))->y,
				((t_vec4*)(vertices->content))->z,
				((t_vec4*)(vertices->content))->w);
		vertices = vertices->next;
	}
}
