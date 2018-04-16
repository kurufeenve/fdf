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
	if (gen->line.k >= -1 && gen->line.k <= 1)
	{
		//printf("aslope x0 = %f\ty0 = %f\tx1 = %f\ty1 = %f\n", gen->line.x0, gen->line.y0, gen->line.x1, gen->line.y1);
		if (gen->line.x0 > gen->line.x1)
			coordswap(&gen->line);
		//printf("aslope	x0 = %f\ty0 = %f\tx1 = %f\ty1 = %f\n", gen->line.x0, gen->line.y0, gen->line.x1, gen->line.y1);
		while (gen->line.x0 < gen->line.x1)
		{
			if (gen->line.x0 < 0 || gen->line.x1 < 0 || gen->line.y0 < 0 || gen->line.y1 < 0)
				return;
			put_pixel(&gen->img, gen->line.x0, gen->line.y0, gen->color);
			//printf("line x = %f\ty = %f\n", gen->line.x0, gen->line.y0);
			gen->line.y0 = gen->line.k * gen->line.x0 + gen->line.b;
			gen->line.x0++;
		}
	}
	else
	{
		//printf("steep x0 = %f\ty0 = %f\tx1 = %f\ty1 = %f\n", gen->line.x0, gen->line.y0, gen->line.x1, gen->line.y1);
		if (gen->line.y0 > gen->line.y1)
			coordswap(&gen->line);
		//printf("steep	x0 = %f\ty0 = %f\tx1 = %f\ty1 = %f\n", gen->line.x0, gen->line.y0, gen->line.x1, gen->line.y1);
		while (gen->line.y0 < gen->line.y1)
		{
			if (gen->line.x0 < 0 || gen->line.x1 < 0 || gen->line.y0 < 0 || gen->line.y1 < 0)
				return;
			put_pixel(&gen->img, gen->line.x0, gen->line.y0, gen->color);
			//printf("line x = %f\ty = %f\n", gen->line.x0, gen->line.y0);
			gen->line.x0 = (gen->line.y0 - gen->line.b) / gen->line.k;
			gen->line.y0++;
		}
	}
}

void	coordswap(t_line *line)
{
	double	x;
	double	y;

	x = line->x0;
	y = line->y0;
	line->x0 = line->x1;
	line->y0 = line->y1;
	line->x1 = x;
	line->y1 = y;
}

int		coefline(t_general	*gen)
{
	gen->line.dx = gen->line.x1 - gen->line.x0;
	gen->line.dy = gen->line.y1 - gen->line.y0;
	if (gen->line.dx == 0)
	{
		vertline(&gen->line, &gen->img, gen->color);
		return (0);
	}
	gen->line.k = gen->line.dy / gen->line.dx;
	gen->line.b = gen->line.y0 - gen->line.k * gen->line.x0;
	return (1);
}

void	vertline(t_line *line, t_img *img, t_color color)
{
	if (line->y1 > line->y0)
		while (line->y1 > line->y0)
		{
			if (line->x0 < 0 || line->x1 < 0 || line->y0 < 0 || line->y1 < 0)
				return;
			put_pixel(img, (int)line->x0, (int)line->y0, color);
			line->y0++;
		}
	if (line->y1 < line->y0)
		while (line->y1 < line->y0)
		{
			if (line->x0 < 0 || line->x1 < 0 || line->y0 < 0 || line->y1 < 0)
				return;
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