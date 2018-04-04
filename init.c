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

void	init_gen(t_general *ptr)
{
	ptr->mlx.init = NULL;
	ptr->mlx.win = NULL;
	ptr->mlx.size_x = 0;
	ptr->mlx.size_y = 0;
	ptr->line.bx = 0;
	ptr->line.by = 0;
	ptr->line.ex = 0;
	ptr->line.ey = 0;
	ptr->line.k = 0;
	ptr->line.b = 0;
	ptr->line.dx = 0;
	ptr->line.dy = 0;
	init_img(&ptr->img);
	init_map(&ptr->map);
}

void	init_img(t_img *img)
{
	img->bpp = 0;
	img->ed = 0;
	img->val = 0;
	img->img = NULL;
	img->image = NULL;
}

void	init_map(t_map *map)
{
	map->len = 0;
	map->rows = 0;
	map->fd = 0;
	map->list = NULL;
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->coefx = 0;
	map->coefy = 0;
}

t_point	init_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
