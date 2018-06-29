/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smyeni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 18:04:32 by smyeni            #+#    #+#             */
/*   Updated: 2017/06/24 18:04:39 by smyeni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pt;
	char	locate;

	locate = c;
	pt = (char*)s;
	while (*pt)
	{
		if (*pt == locate)
			return (pt);
		pt++;
	}
	if (*pt == locate)
		return (pt);
	else
		return (NULL);
}
