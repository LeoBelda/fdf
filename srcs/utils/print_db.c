/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:52:15 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 17:31:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_parsed_map(t_list *vertices)
{
	while (vertices)
	{
		print_vec4(*((t_vec4*)(vertices->content)));
		ft_putendl("");
		vertices = vertices->next;
	}
}
