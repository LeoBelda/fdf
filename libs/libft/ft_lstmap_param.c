/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:42:32 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 02:12:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_param(t_list *lst, void *param,
		t_list *(*f)(t_list *elem, void *param))
{
	t_list	*new;

	new = NULL;
	while (lst)
	{
		ft_lstradd(&new, f(lst, param));
		lst = lst->next;
	}
	return (new);
}
