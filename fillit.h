/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:03:12 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/18 15:57:04 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./Libft/srcs/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_min_max
{
	size_t			x;
	size_t			y;
}					t_min_max;

typedef struct		s_tetris
{
	char			**piece;
	char			c;
	size_t			height;
	size_t			width;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_map
{
	char			**map;
	size_t			size;
}					t_map;

void				ft_error(void);
char				*ft_read_file(char *file_name);
void				ft_check_content(char *file_content);
int					ft_check_symbols(char *file_content);
int					ft_check_pieces(char *pieces);
void				ft_check_sharp(char **piece);
t_tetris			*ft_convert(char **file_content);
size_t				ft_sqrt(size_t nb);
int					ft_tetris_count(t_tetris *tetris);
t_map				*ft_create_map(size_t size);
t_map				*ft_reset_map(t_map *map, size_t size);
char				**ft_crop_piece(char **piece);
int					ft_backtracking(t_map *map, t_tetris *tetris);
void				ft_free_map(t_map *map);
void				ft_free_tab(char **tab, int err);
void				ft_free_tetris(t_tetris *tetris);
#endif
