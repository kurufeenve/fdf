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
	double	coefx;
	double	coefy;
	int		i;

	i = 0;
	coefx = ent->size_x / map->len;
	coefy = ent->size_y / map->rows;
	while (i < (map->rows * map->len))
	{
		map->points[i].x = map->points[i].x * coefx;
		map->points[i].y = map->points[i].y * coefx;
		i++;
	}
}


void		ft_drawpoints(t_map *map, t_img *img, t_color color, t_line *line)
{
	int		i;

	i = 0;
	while (i < (map->rows * map->len))
	{
		if (defhline(line, map, i) == 1)
		put_pixel(img, map->points[i].x, map->points[i].y, color);
		i++;
	}
}