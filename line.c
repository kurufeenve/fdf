/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   y0: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:25:34 y0 vordynsk          #+#    #+#             */
/*   Updated: 2018/02/23 19:25:37 y0 vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

void	plotline(t_general *gen)
{
	if ()
}

void	drawline(t_general	*gen)
{
	gen->line.dx = gen->line.x1 - gen->line.x0;
	gen->line.dy = gen->line.y1 - gen->line.y0;
	if (gen->line.dx == 0)
	{
		vertline(&gen->line, &gen->img, gen->color);
		return ;
	}
	gen->line.k = gen->line.dy / gen->line.dx;
	gen->line.b = gen->line.y0 - gen->line.k * gen->line.x0;
	if ()
}

void	vertline(t_line *line, t_img *img, t_color color)
{
	if ((line->y1 - line->y0) > 0)
		while (line->y0 < line->y1)
		{
			put_pixel(img, (int)line->x0, (int)line->y0, color);
			line->y0++;
		}
	if ((line->y1 - line->y0) < 0)
		while (line->y0 < line->y1)
		{
			put_pixel(img, (int)line->x0, (int)line->y0, color);
			line->y0--;
		}
}

int		defline(t_line *line, t_map *map, int i, int l)
{
	if (l == 0)
	{
		if ((i + 1) % map->len == 0)
			return (0);
		line->x0 = map->points[i].x;
		line->y0 = map->points[i].y;
		i++;
		line->x1 = map->points[i].x;
		line->y1 = map->points[i].y;
		return (1);
	}
	else
	{
		if (i >= (map->rows * map->len - map->len))
			return (0);
		line->x0 = map->points[i].x;
		line->y0 = map->points[i].y;
		i = i + map->len;
		line->x1 = map->points[i].x;
		line->y1 = map->points[i].y;
		return (1);
	}
}