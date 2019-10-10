/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:06:28 by bnoufel           #+#    #+#             */
/*   Updated: 2017/11/17 13:29:25 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_tetris_count(t_tetris *tetris)
{
	size_t	i;

	i = 0;
	while (tetris)
	{
		i++;
		tetris = tetris->next;
	}
	return (i);
}

size_t		ft_sqrt(size_t nb)
{
	size_t	i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}
