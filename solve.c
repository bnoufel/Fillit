/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:44:09 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 15:24:11 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_is_available(t_map *map, t_tetris *tetris, int x, int y)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (tetris->piece[i])
	{
		j = 0;
		while (tetris->piece[i][j])
		{
			if (tetris->piece[i][j] == '#' && map->map[i + y][j + x] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void		ft_add_piece(t_map *map, t_tetris *tetris, int x, int y)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (tetris->piece[i])
	{
		j = 0;
		while (tetris->piece[i][j])
		{
			if (tetris->piece[i][j] == '#')
				map->map[i + y][j + x] = tetris->c;
			j++;
		}
		i++;
	}
}

static void		ft_remove_piece(t_map *map, t_tetris *tetris, int x, int y)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (tetris->piece[i])
	{
		j = 0;
		while (tetris->piece[i][j])
		{
			if (tetris->piece[i][j] == '#')
				map->map[i + y][j + x] = '.';
			j++;
		}
		i++;
	}
}

int				ft_backtracking(t_map *map, t_tetris *tetris)
{
	int			i;
	int			j;

	if (tetris == NULL)
		return (1);
	i = 0;
	while (i < (int)(map->size - tetris->height) + 1)
	{
		j = 0;
		while (j < (int)(map->size - tetris->width) + 1)
		{
			if (ft_is_available(map, tetris, j, i))
			{
				ft_add_piece(map, tetris, j, i);
				if (ft_backtracking(map, tetris->next))
					return (1);
				ft_remove_piece(map, tetris, j, i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
