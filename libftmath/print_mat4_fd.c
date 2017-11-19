/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mat4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:30:21 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 16:22:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

void	print_mat4_fd(t_mat4 mat, int fd)
{
	print_vec4_fd(mat.x, fd);
	write(fd, "\n", 1);
	print_vec4_fd(mat.y, fd);
	write(fd, "\n", 1);
	print_vec4_fd(mat.z, fd);
	write(fd, "\n", 1);
	print_vec4_fd(mat.w, fd);
	write(fd, "\n", 1);
}
