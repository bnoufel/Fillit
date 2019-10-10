/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:57:17 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 13:38:18 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetris	*ft_tetris_new(char *piece)
{
	size_t		i;
	size_t		j;
	char		**split;
	t_tetris	*new;

	i = 0;
	j = 0;
	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!(split = ft_strsplit(piece, '\n')))
		return (NULL);
	if (!(new->piece = ft_crop_piece(split)))
		return (NULL);
	while (new->piece[i][j])
		j++;
	while (new->piece[i])
		i++;
	new->height = i;
	new->width = j;
	new->c = 'A';
	new->next = NULL;
	ft_free_tab(split, 0);
	return (new);
}

static int		ft_tetris_add(t_tetris **tetris, char *piece, char c)
{
	size_t		i;
	size_t		j;
	char		**split;
	t_tetris	*new;

	i = 0;
	j = 0;
	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (0);
	if (!(split = ft_strsplit(piece, '\n')))
		return (0);
	if (!(new->piece = ft_crop_piece(split)))
		return (0);
	while (new->piece[i][j])
		j++;
	while (new->piece[i])
		i++;
	new->height = i;
	new->width = j;
	new->c = c;
	new->next = NULL;
	(*tetris)->next = new;
	ft_free_tab(split, 0);
	return (1);
}

t_tetris		*ft_convert(char **file_content)
{
	t_tetris	*tetris;
	t_tetris	*tmp;
	char		c;
	size_t		i;

	if (!(tetris = ft_tetris_new(file_content[0])))
		return (NULL);
	tmp = tetris;
	c = 'A';
	i = 1;
	while (file_content[i])
	{
		if (!(ft_tetris_add(&tmp, file_content[i], c + i)))
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	ft_free_tab(file_content, 0);
	return (tetris);
}
