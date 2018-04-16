/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:24:58 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/29 14:25:00 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

void	turn(t_general *gen, double a, double b, double g)
{
	int		i;
	double	tmpx;
	double	tmpy;
	double	tmpz;

	i = 0;
	ft_clearscr(&gen->img, &gen->mlx);
	//printf("1. x = %f, y = %f, z = %f\n", gen->map.points[3].x, gen->map.points[3].y, gen->map.points[3].z);
	while (i < gen->map.len * gen->map.rows)
	{
		tmpx = gen->map.points[i].x;
		tmpy = gen->map.points[i].y;
		tmpz = gen->map.points[i].z;
		gen->map.points[i].x = tmpx * cos(b) * cos(g) + tmpz * sin(b) -
		tmpy * cos(b) * sin(g);
		gen->map.points[i].y = -tmpz * cos(b) * sin(a) + tmpx * (cos(g) *
		sin (a) * sin(b) + cos(a) * sin(g)) + tmpy * (cos(a) * cos(g) -
		sin(a) * sin(b) * sin(g));
		gen->map.points[i].z = tmpz * cos(a) * cos(b) + tmpx * (sin(a) *
		sin(g) - cos(a) * cos(g) * sin(b)) + tmpy * (cos(g) * sin(a) +
		cos(a) * sin(b) * sin(g));
		i++;
	}
	//printf("2. x = %f, y = %f, z = %f\n", gen->map.points[3].x, gen->map.points[3].y, gen->map.points[3].z);
	ft_line(gen);
	mlx_put_image_to_window(gen->mlx.init, gen->mlx.win, gen->img.img, 49, 49);
}

void	ft_line(t_general *gen)
{
	int		i;

	i = 0;
	while (i < gen->map.len * gen->map.rows)
	{
		//printf("test1\n");
		defline(&gen->line, &gen->map, i, 0);
		// printf("horisontal gen->line.x0 = %f, gen->line.x1 = %f, gen->line.y0 = %f, gen->line.y1 = %f\n", 
		// gen->line.x0, gen->line.x1, gen->line.y0, gen->line.y1);
		if (coefline(gen) == 1)
			plotline(gen);
		//printf("test2\n");
		defline(&gen->line, &gen->map, i, 1);
		// printf("vertical gen->line.x0 = %f, gen->line.x1 = %f, gen->line.y0 = %f, gen->line.y1 = %f\n", 
		// gen->line.x0, gen->line.x1, gen->line.y0, gen->line.y1);
		if (coefline(gen) == 1)
			plotline(gen);
		//printf("test3\n");
		i++;
	}
	printf("\n========\n\n");
}
