/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:12:56 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/22 18:12:57 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

void	ft_recalc(t_map *map, t_mlx *ent)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	map->coefx = ent->size_x / map->len;
	map->coefy = ent->size_y / map->rows;
	map->points[i].x = -(ent->size_x / 2);
	map->points[i++].y = -(ent->size_y / 2);
	printf("len = %d, rows = %d\nx = %f, y = %f\n", map->len, map->rows, map->points[0].x, map->points[0].y);
	// while (i < (map->rows * map->len))
	// {
	// 	map->points[i].x = map->points[i].x * map->coefx;
	// 	map->points[i].y = map->points[i].y * map->coefy;
	// 	printf("i = %d, x = %f, y = %f\n", i, map->points[i].x, map->points[i].y);
	// 	i++;
	// }
	while (j < map)
}


void		ft_drawpoints(t_map *map, t_img *img, t_color color)
{
	int		i;

	i = 0;
	while (i < (map->rows * map->len))
	{
		put_pixel(img, map->points[i].x, map->points[i].y, color);
		i++;
	}
}

void	ft_clearscr(t_img *img, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->size_x * mlx->size_y * 4)
		img->image[i++] = 0;
}
