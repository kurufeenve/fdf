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
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			k;
	double			b;
	double			dx;
	double			dy;
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

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	//t_color			*color;
}					t_point;

typedef	struct		s_map
{
	int				fd;
	int				rows;
	int				len;
	char			*line;
	t_list			*list;
	t_point			*points;
	double			x;
	double			y;
	double			z;
	double			coefx;
	double			coefy;
}					t_map;

typedef struct		s_general
{
	t_mlx			mlx;
	t_line			line;
	t_img			img;
	t_map			map;
	t_color			color;
}					t_general;

void				init_gen(t_general *ptr);
void				init_img(t_img *img);
void				init_map(t_map *map);
t_point				init_point(double x, double y, double z);
t_line				*ft_coef(t_line *line, t_img *img, t_color color);
int					ft_rdmap(t_map *map, char *filename);
int					ft_map(char *filename, t_map *map);
void				ft_lineparse(t_map *map);
int					ft_countnum(char *line);
void				ft_readlist(t_map *map);
void				ft_recalc(t_map *map, t_mlx *ent);
void				ft_drawpoints(t_map *map, t_img *img, t_color color);
void				put_pixel(t_img *img, int x, int y, t_color color);
void				vertline(t_line *line, t_img *img, t_color color);
int					defline(t_line *line, t_map *map, int i, int l);
void				drawline(t_general	*gen);
void				ft_clearscr(t_img *img, t_mlx *mlx);
int					key_hook(int key, void *ptr);
void				turn(t_general *gen, double a, double b, double g);

#endif
