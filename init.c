/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:31:16 by vordynsk          #+#    #+#             */
/*   Updated: 2018/02/23 19:31:24 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_struct_null(t_mlx **ptr)
{
	*ptr = (t_mlx *)malloc(sizeof(t_mlx));
	(*ptr)->init = NULL;
	(*ptr)->win = NULL;
	(*ptr)->size_x = 0;
	(*ptr)->size_y = 0;
}

void	init_line(t_line **line)
{
	*line = (t_line *)malloc(sizeof(t_line));
	(*line)->bx = 0;
	(*line)->by = 0;
	(*line)->ex = 0;
	(*line)->ey = 0;
	(*line)->k = 0;
	(*line)->b = 0;
}

void	init_img(t_img **img)
{
	*img = (t_img *)malloc(sizeof(t_img));
	(*img)->bpp = 0;
	(*img)->ed = 0;
	(*img)->val = 0;
	(*img)->img = NULL;
	(*img)->image = NULL;
}

void	init_map(t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	(*map)->len = 0;
	(*map)->rows = 0;
	(*map)->fd = 0;
	(*map)->line = NULL;
	(*map)->list = NULL;
	(*map)->x = 0;
	(*map)->y = 0;
	(*map)->z = 0;
}

t_point	init_point(double x, double y, double z)
{
	t_point	point;

	//point = (t_point *)malloc(sizeof(t_point));
	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
