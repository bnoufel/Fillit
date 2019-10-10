/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:25:54 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/17 12:58:10 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_check_nb(char *nb, char *base_from)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (nb[i] == '-')
		i++;
	while (nb[i])
	{
		while (nb[i] != base_from[j])
			j++;
		if (!base_from[j])
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_check_base(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!base || ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (!ft_isprint(base[i]) || base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j + 1])
		{
			if (base[i] == base[j + 1])
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

static int	ft_find_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (c - 'A' + 10);
}

static int	ft_base_to_int(char *nb, char *base_from)
{
	int	i;
	int	power;
	int	value;
	int	base_len;

	i = ft_strlen(nb) - 1;
	power = 1;
	value = 0;
	base_len = ft_strlen(base_from);
	while (i >= 0 && nb[i] != '-')
	{
		value += ft_find_value(nb[i]) * power;
		power = power * base_len;
		i--;
	}
	if (nb[i] == '-')
		value *= -1;
	return (value);
}

char		*ft_convert_base(char *nb, char *base_from, char *base_to)
{
	char	*result;
	int		value;
	size_t	len_base_to;
	int		i;
	int		sign;

	if (!nb || !ft_check_base(base_from) || !ft_check_base(base_to)
			|| !ft_check_nb(nb, base_from) || ft_strlen(nb) > 33
			|| !(result = (char *)ft_memalloc(34)))
		return (NULL);
	value = ft_base_to_int(nb, base_from);
	len_base_to = ft_strlen(base_to);
	i = 0;
	value < 0 ? sign = -1 : 1;
	value < 0 ? value *= -1 : 1;
	if (value == 0)
		result[i] = base_to[0];
	while (value > 0)
	{
		result[i] = base_to[value % len_base_to];
		value /= len_base_to;
		++i;
	}
	sign == -1 ? result[i] = '-' : 1;
	return (ft_strrev(result));
}
