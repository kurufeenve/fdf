/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:25:34 by vordynsk          #+#    #+#             */
/*   Updated: 2018/02/23 19:25:37 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

t_line	*ft_coef(t_line *line, t_img *img, t_color color)
{
	line->dx = line->ex - line->bx;
	line->dy = line->ey - line->by;
	if (line->dx == 0)
	{
		vertline(line, img, color);
		return (0);
	}
	line->k = line->dy / line->dx;
	line->b = line->by - line->k * line->bx;
	if (line->k >= -1 || line->k <= 1)
	drawline(line, img, color);
	return (line);
}

void	vertline(t_line *line, t_img *img, t_color color)
{
	if ((line->ey - line->by) > 0)
		while (line->by < line->ey)
		{
			put_pixel(img, (int)line->bx, (int)line->by, color);
			line->by++;
		}
	if ((line->ey - line->by) < 0)
		while (line->by < line->ey)
		{
			put_pixel(img, (int)line->bx, (int)line->by, color);
			line->by--;
		}
}

int		defline(t_line *line, t_map *map, int i, int l)
{
	if (l == 0)
	{
		if (map->points[i].x == (map->coefx * map->len) - map->coefx)
			return (0);
		line->bx = map->points[i].x;
		line->by = map->points[i].y;
		line->ex = map->points[i].x + map->coefx;
		line->ey = map->points[i].y;
		return (1);
	}
	else
	{
		if (map->points[i].y == (map->coefy * map->rows) - map->coefy)
			return (0);
		line->bx = map->points[i].x;
		line->by = map->points[i].y;
		line->ex = map->points[i].x;
		line->ey = map->points[i].y + map->coefy;
		return (1);
	}
}

void	drawline(t_line *line, t_img *img, t_color color)
{
	if (line->k <= 1 && line->k >= -1)
		while (line->bx <= line->ex)
		{
			put_pixel(img, (int)line->bx, (int)line->by, color);
			line->by = line->k * line->bx + line->b;
			printf("line->bx = %f\tline->by = %f\n", line->bx, line->by);
			line->bx++;
		}
	else
		while (line->bx <= line->ex)
		{
			put_pixel(img, (int)line->bx, (int)line->by, color);
			line->bx = (line->by - line->b) / line->k;
			printf("line->bx = %f\tline->by = %f\n", line->bx, line->by);
			line->by++;
		}
}

void	ft_line(t_line *line, t_map *map, t_color color, t_img *img)
{
	int		i;

	i = 0;
	while (i < map->len * map->rows)
	{
		defline(line, map, i, 0);
		ft_coef(line, img, color);
		defline(line, map, i, 1);
		ft_coef(line, img, color);
		i++;
	}
}
