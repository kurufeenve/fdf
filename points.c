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

	i = 0;
	printf("map->len = %d, map->rows = %d\n", map->len, map->rows);
	map->coefx = ent->size_x / map->len;
	map->coefy = ent->size_y / map->rows;
	while (i < (map->rows * map->len))
	{
		map->points[i].x = map->points[i].x * map->coefx;
		map->points[i].y = map->points[i].y * map->coefx;
		i++;
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

void	ft_clearscr(t_img *img)
{
	char	*buff;

	buff = img->image;
	while (*buff != '\0')
	{
		*buff = 0;
	}
}
