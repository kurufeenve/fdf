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

int			ft_map(char *filename, t_map *map)
{
	if (ft_rdmap(map, filename) == 0)
	{	
		printf("ft_rdmap returned 0\n");
		return (0);
	}
	ft_lineparse(map);
	return (1);
}

int			ft_rdmap(t_map *map, char *filename)
{
	int		buff;
	int		l;

	l = 0;
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
		return (0);
	while (get_next_line(map->fd, &map->line) > 0)
	{
		buff = ft_countnum(map->line);
		if (map->len == buff)
			map->len = buff;
		else if (l == 0)
			map->len = buff;
		else
			return (0);
		l = 1;
		ft_lstaddend(&map->list, ft_lstnew(map->line, ft_strlen(map->line)));
		if(map->line != NULL)
			map->rows++;
		ft_strdel(&map->line);
	}
	return (1);
}

void		ft_lineparse(t_map *map)
{
	t_list	*buff;
	char	*buff2;
	int		i;

	buff = map->list;
	i = 0;
	map->points = (t_point *)malloc(sizeof(t_point) *
	(map->rows * map->len));
	while (buff != NULL)
	{
		map->x = 0;
		buff2 = buff->content;
		while (buff2[1] != '\0')
		{
			while (*buff2 == ' ')
				buff2++;
			map->z = ft_atoi(buff2);
			while ((*buff2 >= '0' && *buff2 <= '9') || *buff2 == '-')
				buff2++;
			if (*buff2 == '\0')
				break ;
			map->points[i] = init_point(map->x, map->y, map->z);
			map->x++;
			i++;
		}
		map->y++;
		buff = buff->next;
	}
}

void		ft_readlist(t_map *map)
{
	int		i;

	i = 0;
	while (i < (map->rows * map->len))
	{
		printf("i = %d, x = %f, y = %f, z = %f\n", i, map->points[i].x, map->points[i].y, map->points[i].z);
		i++;
	}
}

int			ft_countnum(char *line)
{
	int		count;
	int		i;
	int		l;

	count = 0;
	i = 0;
	l = 0;
	if (!line || ft_strlen(line) <= 0)
		return (0);
	while (line[i] != '\0')
	{
		if (l == 0 && ft_isdigit(line[i]) == 1)
		{
			l = 1;
			count ++;
		}
		else if (ft_isdigit(line[i]) == 0)
			l = 0;
		i++;
	}
	return (count);
}
