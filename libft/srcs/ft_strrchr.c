/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:00:07 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 16:57:15 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_index;

	s_index = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s + s_index >= s)
	{
		if (*(s + s_index) == c)
			return ((char *)(s + s_index));
		else
			s_index--;
	}
	return (NULL);
}
