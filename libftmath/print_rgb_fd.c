/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 23:07:12 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 23:19:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

static void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		to_write;

	nb = (long int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	to_write = nb % 10 + 48;
	write(fd, &(to_write), 1);
}

void	print_rgb_fd(t_rgb rgb, int fd)
{
	write(fd, "a: ", 3);
	ft_putnbr_fd(rgb.a, fd);
	write(fd, "  ", 2);
	write(fd, "r: ", 3);
	ft_putnbr_fd(rgb.r, fd);
	write(fd, "  ", 2);
	write(fd, "g: ", 3);
	ft_putnbr_fd(rgb.g, fd);
	write(fd, "  ", 2);
	write(fd, "b: ", 3);
	ft_putnbr_fd(rgb.b, fd);
	write(fd, "  ", 2);
}
