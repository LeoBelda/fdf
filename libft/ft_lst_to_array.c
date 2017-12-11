/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:29:02 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 02:12:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_to_array(t_list *lst)
{
	size_t			size_elem;
	size_t			nb_elem;
	size_t			i;
	unsigned char	*array;

	i = 0;
	size_elem = lst->content_size;
	nb_elem = ft_lstcount(lst);
	if (!(array = ft_memalloc(nb_elem * size_elem)))
		return (NULL);
	while (i < nb_elem)
	{
		ft_memcpy(&(array[i * size_elem]), lst->content, size_elem);
		lst = lst->next;
		i++;
	}
	return (array);
}
