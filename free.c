/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 09:56:52 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 13:26:55 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_tab(char **tab, int err)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
	if (err)
		ft_error();
}

void	ft_free_map(t_map *map)
{
	if (map)
	{
		ft_free_tab(map->map, 0);
		free(map);
		map = NULL;
	}
}

void	ft_free_tetris(t_tetris *tetris)
{
	if (tetris)
	{
		ft_free_tab(tetris->piece, 0);
		ft_free_tetris(tetris->next);
		free(tetris);
		tetris = NULL;
	}
}
