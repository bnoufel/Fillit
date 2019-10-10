/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:48:47 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 16:55:11 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*adr;

	adr = (unsigned char *)s;
	while (n--)
	{
		if (*adr == (unsigned char)c)
			return ((void *)adr);
		else
			adr++;
	}
	return (NULL);
}
