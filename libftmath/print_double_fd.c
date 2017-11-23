/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:33:33 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 01:19:59 by lbelda           ###   ########.fr       */
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

void		print_double_fd(double nb, int fd)
{
	double intpart;
	double decpart;

	decpart = modf(nb, &intpart);
	ft_putnbr_fd((int)lround(intpart), fd);
	write(fd, ".", 1);
	ft_putnbr_fd((int)lround(decpart * 100000.0), fd);
}
