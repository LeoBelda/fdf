/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:40:40 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/10 18:57:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

t_list		*ft_strsplit_lst(char const *s, char c)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	lst = NULL;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			len = word_len(&(s[i]), c);
			if (!(tmp = ft_lstnew(ft_strndup(&(s[i]), len), len)))
				return (NULL);
			ft_lstradd(&lst, tmp);
		}
		i += (len ? len : 1);
	}
	return (lst);
}
