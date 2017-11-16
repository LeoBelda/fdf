/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:20:41 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/07 18:24:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmemendl_fd(void const *s, size_t len, int fd)
{
	ft_putmem_fd(s, len, fd);
	ft_putchar_fd('\n', fd);
}
