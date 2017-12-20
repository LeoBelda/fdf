/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:21:08 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/16 23:54:50 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lst_pop_out(t_list **begin_lst, int fd)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *begin_lst;
	if (((t_stock*)((*begin_lst)->content))->fd == fd)
	{
		*begin_lst = (*begin_lst)->next;
		free((t_stock*)(tmp->content));
		free(tmp);
		return ;
	}
	prev = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (((t_stock*)(tmp->content))->fd == fd)
		{
			prev->next = tmp->next;
			free((t_stock*)(tmp->content));
			free(tmp);
			return ;
		}
		prev = prev->next;
		tmp = tmp->next;
	}
}

static char	*manage_stock(const int fd, const int rm)
{
	static t_list	*stocks;
	t_list			*tmp;
	char			*current;
	t_stock			new;

	tmp = stocks;
	current = NULL;
	if (rm)
	{
		lst_pop_out(&stocks, fd);
		return (NULL);
	}
	while (tmp)
	{
		if (((t_stock*)(tmp->content))->fd == fd)
			return (current = ((t_stock*)(tmp->content))->stock);
		tmp = tmp->next;
	}
	ft_bzero(new.stock, BUFF_SIZE + 1);
	new.fd = fd;
	if (!(tmp = ft_lstnew(&new, sizeof(t_stock))))
		return (NULL);
	ft_lstadd(&stocks, tmp);
	return (current = ((t_stock*)(stocks->content))->stock);
}

static int	stock_to_line(char *stock, char **line)
{
	size_t	len;
	char	*to_free;
	char	*to_freeb;
	int		ret;

	ret = (ft_strchr(stock, '\n') ? 0 : 1);
	len = ft_strcspn(stock, "\n");
	if (!*line)
	{
		if (!(*line = ft_strndup(stock, len)))
			return (-1);
	}
	else
	{
		to_free = *line;
		if (!(to_freeb = ft_strndup(stock, len)))
			return (-1);
		if (!(*line = ft_strjoin(*line, to_freeb)))
			return (-1);
		ft_strdel(&to_free);
		ft_strdel(&to_freeb);
	}
	(len == ft_strlen(stock)) ? ft_bzero(stock, BUFF_SIZE)
							: ft_strncpy(stock, &(stock[len + 1]), BUFF_SIZE);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	char	*stock;
	int		ret1;
	int		ret2;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (fd < 0 || !(stock = manage_stock(fd, 0)))
		return (-1);
	while (!*stock || (ret1 = stock_to_line(stock, line)) == 1)
	{
		if (!(ret2 = read(fd, stock, BUFF_SIZE)))
			break ;
		else if (ret2 == -1)
			return (-1);
	}
	if (ret1 == -1)
		return (-1);
	if (!*line)
		manage_stock(fd, 1);
	return (*line != NULL);
}
