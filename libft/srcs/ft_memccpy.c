/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:48:29 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 16:54:31 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	unsigned char		letter;

	pdest = dest;
	psrc = src;
	letter = c;
	while (n--)
	{
		if ((*pdest++ = *psrc++) == letter)
			return (pdest);
	}
	return (NULL);
}
