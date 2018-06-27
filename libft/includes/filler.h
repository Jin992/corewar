/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:39:52 by earteshc          #+#    #+#             */
/*   Updated: 2018/03/06 13:40:07 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_fdata
{
	char	**map;
	char	**piece;
	char	player;
	int		zero_point[2];
	int		*x;
	int		*y;
	int		arr_size;
	int		row;
	int		col;
	int		x_shift;
	int		y_shift;
	int		*decision_x;
	int		*decision_y;
	int		origin_y;
	int		origin_x;
	int		decisions_cnt;

}				t_fdata;

char			**get_map(char **line, char *player, t_fdata *data);
char			**get_piece(char **line);
int				enemy_marker(char marker, t_fdata *data);
void			*ft_realloc_mod(void *ptr, size_t size, size_t old_size);
int				search_position(t_fdata *data);
int				shift_x_cord(t_fdata *data);
int				shift_y_cord(t_fdata *data);
void			init_cords(t_fdata *data);
int				transform_mapl(t_fdata *data);
int				get_piece_cords(t_fdata *piece);
int				cords_init_position(t_fdata *data);
int				best_place(t_fdata *data);

#endif
