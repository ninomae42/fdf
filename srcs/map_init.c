/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:49:31 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 16:28:10 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// initialize map struct. load map file given by filename
// If no map error detected then returns 0, otherwise returns 1
t_map	*init_map(char *file_name)
{
	t_map	*map;
	int		fd;

	map = ft_malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	fd = open_file_by_name(file_name);
	if (set_map_width_height(fd, map) != 0
		|| INT_MAX < map->cols || INT_MAX < map->rows)
	{
		ft_putendl_fd(ERR_MAP, STDERR_FILENO);
		free(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	map->points = (t_point *)ft_malloc(
			sizeof(t_point) * (map->rows * map->cols));
	ft_bzero(map->points, (sizeof(t_point) * (map->rows * map->cols)));
	if (read_map(file_name, map) != 0)
	{
		deallocate_map(map);
		return (NULL);
	}
	return (map);
}

// copy map struct.
t_map	*copy_map(t_map *map)
{
	t_map	*map_new;

	map_new = ft_malloc(sizeof(t_map));
	ft_bzero(map_new, sizeof(t_map));
	map_new->rows = map->rows;
	map_new->cols = map->cols;
	map_new->points = (t_point *)ft_malloc(
			sizeof(t_point) * (map_new->cols * map_new->rows));
	ft_memcpy(map_new->points, map->points,
		(sizeof(t_point) * (map->cols * map->rows)));
	return (map_new);
}

// deallocate map struct.
void	deallocate_map(t_map *map)
{
	free(map->points);
	free(map);
}
