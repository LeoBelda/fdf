/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec4_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:10:22 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 16:18:25 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

void	print_vec4_fd(t_vec4 vec, int fd)
{
	write(fd, "x: ", 3);
	print_double_fd(vec.x, fd);
	write(fd, "  ", 2);
	write(fd, "y: ", 3);
	print_double_fd(vec.y, fd);
	write(fd, "  ", 2);
	write(fd, "z: ", 3);
	print_double_fd(vec.z, fd);
	write(fd, "  ", 2);
	write(fd, "w: ", 3);
	print_double_fd(vec.w, fd);
}
