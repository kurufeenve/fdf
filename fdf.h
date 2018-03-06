/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:11:38 by vordynsk          #+#    #+#             */
/*   Updated: 2018/02/13 19:11:39 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	int				size_x;
	int				size_y;

}					t_mlx;

typedef struct		s_line
{
	double			bx;
	double			by;
	double			ex;
	double			ey;
	double			k;
	double			b;
	int				t;
	int				*l;
}					t_line;

typedef union		s_color
{
	int				color;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_img
{
	void			*img;
	char			*image;
	int				bpp;
	int				val;
	int				ed;
}					t_img;

typedef	struct		s_pixel
{
	int				index;
	int				color;
}					t_pixel;

typedef	struct		s_map
{
	int				fd;
	int				rows;
	size_t			len;
	t_list			*points;
	t_list			*row;
	int				check;
	char			*line;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

void				mlx_struct_null(t_mlx **ptr);
void				init_line(t_line **line);
void				init_img(t_img **img);
void				init_map(t_map **map);
void				init_point(t_point **point);
t_line				*ft_coef(t_line *line);
int					ft_rdmap(t_map **map, char *filename);
int					ft_map(char *filename);
void				ft_lineparse(char *line, int y, t_list **points);

#endif
