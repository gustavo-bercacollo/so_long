/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:13:53 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/13 17:13:53 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}

static int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static int	fill_grid(const char *filename, t_map *map)
{
	int		y;
	int		fd;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		line[strcspn(line, "\n")] = '\0';
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\r')
			line[len - 1] = '\0';
		map->grid[y++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	return (y == map->height);
}

static int	set_width(t_map *map)
{
	map->width = 0;
	if (map->grid[0])
	{
		while (map->grid[0][map->width] != '\0')
			map->width++;
	}
	return (map->width);
}

t_map	*read_map(const char *filename)
{
	t_map	*map;
	int		height;
	int		i;

	height = count_lines(filename);
	map = malloc(sizeof(t_map));
	if (!map || height <= 0)
		return (NULL);
	map->height = height;
	map->grid = malloc(height * sizeof(char *));
	i = 0;
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	while (i < height)
		map->grid[i++] = NULL;
	if (!fill_grid(filename, map))
	{
		free_map(map);
		return (NULL);
	}
	map->width = set_width(map);
	return (map);
}
