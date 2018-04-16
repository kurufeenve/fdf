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
	map->coefx = (ent->size_x - 100) / (map->len - 1);
	map->coefy = (ent->size_y - 100) / (map->rows - 1);
	map->points[0].x = 0;
	map->points[0].y = 0;
	//printf("len = %d, rows = %d\ni = 0, x = %f, y = %f\n", map->len, map->rows, map->points[0].x, map->points[0].y);
	while (j < map->rows)
	{
		k = 0;
		while (k < map->len)
		{
			map->points[i].x = map->coefx * k;
			map->points[i].y = map->coefy * j;
			//printf("i = %d, x = %f, y = %f, coefx = %f, coefy = %f, k = %d, j = %d\n", i, map->points[i].x, map->points[i].y, map->coefx, map->coefy, k, j);
			k++;
			i++;
		}
		j++;
	}
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
