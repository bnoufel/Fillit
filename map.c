/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:50:54 by bnoufel           #+#    #+#             */
/*   Updated: 2017/11/18 11:54:19 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_map(size_t size)
{
	t_map	*map;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map->map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = NULL;
	map->size = size;
	return (map);
}

t_map	*ft_reset_map(t_map *map, size_t size)
{
	ft_free_map(map);
	if (!(map = ft_create_map(size + 1)))
		return (NULL);
	return (map);
}
