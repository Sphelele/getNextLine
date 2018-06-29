/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smyeni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 18:12:31 by smyeni            #+#    #+#             */
/*   Updated: 2017/06/24 18:13:16 by smyeni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <fcntl.h>
# include "libft/includes/libft.h"

int					get_next_line(int const fd, char **line);

typedef struct		s_list
{
	int					fd;
	char				*str;
	struct s_list		*next;
}					t_list;

#endif
