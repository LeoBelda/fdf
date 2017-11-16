/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:16:37 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/10 13:59:03 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	len = (n > len ? len : n);
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	ft_strncpy(s2, s1, len);
	return (s2);
}
