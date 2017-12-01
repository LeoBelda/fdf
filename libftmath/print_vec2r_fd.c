/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec2r_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:51:29 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 18:57:47 by lbelda           ###   ########.fr       */
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

void		print_vec2r_fd(t_vec2r vec, int fd)
{
	write(fd, "x: ", 3);
	ft_putnbr_fd(vec.x, fd);
	write(fd, "  ", 2);
	write(fd, "y: ", 3);
	ft_putnbr_fd(vec.y, fd);
}
