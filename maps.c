/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:55:36 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/02 15:55:38 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

int			ft_map(char *filename)
{
	t_map	*map;

	init_map(&map);
	if (ft_rdmap(&map, filename) == 0)
		return (0);
	ft_lstiter(map->points, read_points);
	printf("map->line = %s\nmap->rows = %d\n", map->line, map->rows);
	return (1);
}

int			ft_rdmap(t_map **map, char *filename)
{
	t_list	*points;

	(*map)->fd = open(filename, O_RDONLY);
	if ((*map)->fd < 0)
		return (0);
	while ((*map)->check > 0)
	{
		(*map)->check = get_next_line((*map)->fd, &(*map)->line);
		ft_lineparse(map, &points);
		printf("\n");
		if((*map)->line != NULL)
			(*map)->rows++;
	}
	if ((*map)->check < 0)
		return (0);
	return (1);
}

int			ft_lineparse(t_map **map, t_list **points)
{
	t_point	*point;
	char	*buff;

	init_point(&point);
	point->x = 0;
	if ((*map)->line == NULL)
		return (0);
	buff = ft_strnew(ft_strlen((*map)->line) + 1);
	buff = ft_strcpy(buff, (*map)->line);
	while (*buff != '\0')
	{
		point->y = (*map)->rows;
		point->z = ft_atoi(buff);
		while (ft_isdigit(*buff) == 1 || *buff == '-')
			buff++;
		if (*buff == ' ')
			buff++;
		//printf("x = %d\ty = %d\tz = %d\n", point->x, point->y, point->z);
		if (!*points)
			*points = ft_lstnew(point, sizeof(t_point));
		else
			ft_lstadd(points, ft_lstnew(point, sizeof(t_point)));
		(*points)->content = point;
		point->x++;
	}
	if (rawlenvalidation(map, point->x) == 0)
		return (0);
	return (1);
}

int			rawlenvalidation(t_map **map, int numpoints)
{
	if ((*map)->len == 0)
	{
		(*map)->len = numpoints;
		return (1);
	}
	else if ((*map)->len != numpoints && (*map)->len > 0)
		return (0);
	return (1);
}

void		read_points(t_list *points)
{
	t_point	*point;

	point = (t_point *)points->content;
	printf("x = %d\ty = %d\tz = %d\n", (int)point->x, (int)point->y, (int)point->z);
}
