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
		ft_lineparse((*map)->line, (*map)->rows, &points);
		printf("\n");
		(*map)->rows++;
	}
	if ((*map)->check < 0)
		return (0);
	return (1);
}

void		ft_lineparse(char *line, int y, t_list **points)
{
	t_point	*point;
	int		i;
	int		test;
	int		oatoi;

	init_point(&point);
	point->y = y;
	i = 0;
	printf("line = %s\tlen = %zu\n", line, ft_strlen(line));
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			line++;
			i++;
		}
		test = ft_atoi(line);
		oatoi = atoi(line);
		printf("test = %d\tatoi = %d\n", test, oatoi);
		line++;
		i++;
	}
	if (!*points)
		*points = ft_lstnew(point, sizeof(t_point));
}

