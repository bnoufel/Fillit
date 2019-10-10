/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:40:52 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 13:24:25 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_min_max		*ft_get_min(char **piece)
{
	size_t				i;
	size_t				j;
	t_min_max			*min;

	i = 0;
	if (!(min = (t_min_max *)malloc(sizeof(t_min_max))))
		return (NULL);
	min->x = 3;
	min->y = 3;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			piece[i][j] == '#' && j < min->x ? min->x = j : 1;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		i = -1;
		while (++i < 4)
			piece[i][j] == '#' && (3 - i) < min->y ? min->y = (3 - i) : 1;
		j++;
	}
	return (min);
}

static t_min_max		*ft_get_max(char **piece)
{
	size_t				i;
	size_t				j;
	t_min_max			*max;

	i = 0;
	if (!(max = (t_min_max *)malloc(sizeof(t_min_max))))
		return (NULL);
	max->x = 0;
	max->y = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			piece[i][j] == '#' && j > max->x ? max->x = j : 1;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		i = -1;
		while (++i < 4)
			piece[i][j] == '#' && (3 - i) > max->y ? max->y = (3 - i) : 1;
		j++;
	}
	return (max);
}

static char				*ft_get_cropped(char **piece, size_t n, t_min_max *min,
		t_min_max *max)
{
	size_t				i;
	size_t				j;
	size_t				k;
	char				*new;

	i = (3 - max->y) + n;
	j = min->x;
	k = 0;
	if (!(new = (char *)malloc(sizeof(char) * (((max->x + 1) - min->x) + 1))))
		return (NULL);
	while (piece[i][j] && j <= max->x)
	{
		new[k] = piece[i][j];
		j++;
		k++;
	}
	new[k] = '\0';
	return (new);
}

char					**ft_crop_piece(char **piece)
{
	size_t				i;
	char				**new;
	t_min_max			*min;
	t_min_max			*max;

	i = 0;
	min = ft_get_min(piece);
	max = ft_get_max(piece);
	if (!(new = (char **)malloc(sizeof(char *) *
					(((max->y + 1) - min->y) + 1))))
		return (NULL);
	while (i < ((max->y + 1) - min->y))
	{
		new[i] = ft_get_cropped(piece, i, min, max);
		i++;
	}
	new[i] = NULL;
	free(max);
	free(min);
	return (new);
}
