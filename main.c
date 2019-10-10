/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 06:38:49 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 13:35:54 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_error(void)
{
	write(1, "error\n", 6);
	exit(-1);
}

static t_tetris		*ft_check(char *file_name)
{
	char			*file_content;
	char			**tetris_pieces;
	size_t			piece_amount;
	size_t			i;

	if (!(file_content = ft_read_file(file_name)))
		return (NULL);
	ft_check_content(file_content);
	if ((piece_amount = ft_check_symbols(file_content)) > 26)
	{
		free(file_content);
		ft_error();
	}
	i = -1;
	if (!(tetris_pieces = (char **)malloc(sizeof(char *) * (piece_amount + 1))))
		return (NULL);
	while (++i < piece_amount)
		tetris_pieces[i] = ft_strndup(file_content + (i * 21), 20);
	tetris_pieces[i] = NULL;
	free(file_content);
	i = -1;
	while (tetris_pieces[++i])
		if (!ft_check_pieces(tetris_pieces[i]))
			ft_free_tab(tetris_pieces, 1);
	return (ft_convert(tetris_pieces));
}

int					main(int argc, char **argv)
{
	size_t			i;
	t_tetris		*tetris;
	t_map			*map;

	i = 0;
	if (argc != 2)
		ft_error();
	if (!(tetris = ft_check(argv[1])))
		return (0);
	if (!(map = ft_create_map(ft_sqrt(ft_tetris_count(tetris) * 4))))
		return (0);
	while (!(ft_backtracking(map, tetris)))
		map = ft_reset_map(map, map->size);
	while (map->map[i])
	{
		ft_putendl(map->map[i]);
		i++;
	}
	ft_free_map(map);
	ft_free_tetris(tetris);
	return (0);
}
