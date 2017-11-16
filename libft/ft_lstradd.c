/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:04:19 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/09 17:26:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstradd(t_list **alst, t_list *new)
{
	t_list	*i;

	if (!*alst)
		*alst = new;
	else
	{
		i = *alst;
		while (i->next)
			i = i->next;
		i->next = new;
	}
}
