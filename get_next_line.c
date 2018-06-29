/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smyeni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:58:36 by smyeni            #+#    #+#             */
/*   Updated: 2017/06/24 18:19:20 by smyeni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*init_list(int fd)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->fd = fd;
	if (!(node->str = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	if (read(fd, node->str, BUFF_SIZE) == -1)
		return (NULL);
	node->next = NULL;
	return (node);
}

static t_list			*curr_node(t_list *head, int fd)
{
	t_list	*node;

	while (head)
	{
		if (head->fd == fd)
			return (head);
		if (!(head->next))
			break ;
		head = head->next;
	}
	if (!(node = init_list(fd)))
		return (NULL);
	head->next = node;
	return (node);
}

static void				get_line(t_list *node, char **line, char *pos)
{
	char	*first;
	char	*sec;
	char	*free;

	first = ft_strsub(node->str, 0, pos - node->str);
	sec = ft_strsub(node->str, (pos - node->str) + 1, ft_strlen(node->str));
	free = *line;
	*line = ft_strjoin(*line, first);
	ft_memdel((void **)&free);
	ft_memdel((void **)&first);
	ft_memdel((void **)&(node->str));
	node->str = sec;
}

static int				read_line(int fd, t_list *node, char **line)
{
	char	*pos;
	int		size;
	int		length;
	char	*free;

	size = 1;
	while (size > 0)
	{
		if ((pos = ft_strchr(node->str, '\n')))
		{
			get_line(node, line, pos);
			return (1);
		}
		free = *line;
		*line = ft_strjoin(*line, node->str);
		ft_memdel((void **)&free);
		length = ft_strlen(node->str);
		ft_memdel((void **)&(node->str));
		if (!(node->str = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		size = read(fd, node->str, BUFF_SIZE);
		if (!length && !size)
			return (0);
	}
	return (1);
}

int						get_next_line(int const fd, char **line)
{
	static t_list	*head;
	t_list			*curr;

	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!head)
		if (!(head = init_list(fd)))
			return (-1);
	*line = ft_strnew(1);
	if (!(curr = curr_node(head, fd)))
		return (-1);
	return (read_line(fd, curr, line));
}
