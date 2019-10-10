/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:55:43 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 16:59:43 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	size_t	i;
	char	*new_s;

	i = 0;
	if (!s)
		return (NULL);
	if ((new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		new_s[i] = (*f)(s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
