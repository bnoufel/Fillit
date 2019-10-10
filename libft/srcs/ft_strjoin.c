/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:55:14 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/14 07:34:08 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*new_s;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	new_s[ft_strlen(s1) + i] = '\0';
	return (new_s);
}
