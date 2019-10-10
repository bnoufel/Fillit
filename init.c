/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:00:05 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 16:05:29 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_file(char *file_name)
{
	int		fd;
	char	*c;
	char	*tmp;
	char	*file_content;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error();
	if (!(c = (char *)ft_memalloc(2))
			|| !(file_content = (char *)ft_memalloc(1)))
		return (NULL);
	while (read(fd, c, 1) >= 1)
	{
		tmp = file_content;
		if (!(file_content = ft_strjoin(file_content, c)))
			return (NULL);
		free(tmp);
	}
	free(c);
	if ((close(fd)) == -1)
	{
		free(file_content);
		ft_error();
	}
	return (file_content);
}

void		ft_check_content(char *file_content)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (file_content[i])
	{
		if ((i - j + 1) % 5 == 0 && i)
			file_content[i] != '\n' ? ft_error() : 1;
		else if ((i + 1) % 21 == 0 && i)
			file_content[i] != '\n' ? ft_error() : j++;
		else
		{
			if (file_content[i] != '.' && file_content[i] != '#'
					&& file_content[i])
			{
				free(file_content);
				ft_error();
			}
		}
		i++;
	}
}

int			ft_check_symbols(char *file_content)
{
	size_t	i;
	size_t	sharp;

	i = 0;
	sharp = 0;
	while (file_content[i])
	{
		if (file_content[i] == '#')
			sharp++;
		i++;
	}
	if (sharp % 4 || sharp == 0 || (i + 1) % 21)
	{
		free(file_content);
		ft_error();
	}
	return (sharp / 4);
}

int			ft_check_pieces(char *pieces)
{
	size_t	i;
	int		link;
	int		sharp;

	i = 0;
	link = 0;
	sharp = 0;
	while (i < 19)
	{
		if (pieces[i] == '#')
		{
			i < 19 && pieces[i + 1] == '#' ? link++ : 1;
			i > 0 && pieces[i - 1] == '#' ? link++ : 1;
			i < 14 && pieces[i + 5] == '#' ? link++ : 1;
			i > 4 && pieces[i - 5] == '#' ? link++ : 1;
			sharp++;
		}
		i++;
	}
	if ((link != 6 && link != 8) || sharp != 4)
		return (0);
	return (1);
}
