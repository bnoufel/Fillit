/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:48:14 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/11 15:10:33 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_digits(int n)
{
	size_t			i;
	unsigned int	abs_n;

	i = 0;
	abs_n = n;
	if (n < 0)
	{
		i++;
		abs_n = -n;
	}
	if (abs_n < 10)
		i++;
	else
	{
		while (abs_n > 9)
		{
			i++;
			abs_n /= 10;
		}
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			i;
	unsigned int	abs_n;
	char			*result;

	i = 0;
	abs_n = n;
	if ((result = (char *)malloc(sizeof(char) * (ft_digits(n) + 1))) == NULL)
		return (NULL);
	if (n < 0)
		abs_n = -n;
	while (abs_n > 9)
	{
		result[i] = abs_n % 10 + '0';
		abs_n /= 10;
		i++;
	}
	result[i] = abs_n % 10 + '0';
	if (n < 0)
	{
		result[i + 1] = '-';
		result[i + 2] = '\0';
	}
	else
		result[i + 1] = '\0';
	return (ft_strrev(result));
}
