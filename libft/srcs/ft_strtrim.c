/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:51:58 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/10 11:08:46 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n'
			|| c == '\f')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		new_len;
	char	*new_s;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	k = 0;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[j - 1]))
		j--;
	if ((new_len = j - i) < 0)
		new_len = 0;
	if ((new_s = (char *)malloc(sizeof(char) * (new_len) + 1)) == NULL)
		return (NULL);
	while (k < (size_t)new_len && s[i])
		new_s[k++] = s[i++];
	new_s[k] = '\0';
	return (new_s);
}
